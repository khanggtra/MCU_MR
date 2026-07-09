/**
 * @file    hal_adc.c
 * @author  Tran Gia Khang
 * @brief   Hardware Abstraction Layer implementation for ADC on PIC16F887.
 * @version 1.2
 */

#include "hal_adc.h"
#include "../../project_config/project_config.h"
#include <xc.h>


/* ==============================================================================
 * PRIVATE VARIABLES (Encapsulated)
 * ============================================================================== */

/* Array to store the latest converted values for each channel. 
 * Initialized to 0. 'volatile' is mandatory as it is updated within an ISR. 
 */
static volatile uint16_t adc_channel_values[15] = {0};  

/* Tracks the currently active channel. 14 represents an 'Idle' state. */
static volatile uint8_t current_adc_channel = 14; 


/* ==============================================================================
 * API FUNCTION IMPLEMENTATIONS
 * ============================================================================== */

void HAL_ADC_Init(adc_clock_t clk, adc_vref_t vref) {
    /* 1. Configure Result Format: Right Justified */
    ADCON1bits.ADFM = 1;

    /* 2. Configure Voltage Reference */
    if (vref == ADC_VREF_INTERNAL) {
        ADCON1bits.VCFG0 = 0; 
        ADCON1bits.VCFG1 = 0; 
    } else {
        ADCON1bits.VCFG0 = 1; 
        ADCON1bits.VCFG1 = 1; 
    }

    /* 3. Configure Clock Source */
    ADCON0bits.ADCS = clk & 0x03;

    /* 4. Enable ADC Module */
    ADCON0bits.ADON = 1;
    
    /* 5. Enable Peripheral Interrupts for ADC */
    PIR1bits.ADIF = 0;   /* Clear interrupt flag */
    PIE1bits.ADIE = 1;   /* Enable ADC interrupt */
}

void HAL_ADC_ConfigChannel(adc_channel_t ch) {
    /* Map channels to TRIS and ANSEL/ANSELH registers */
    switch (ch) {
        case ADC_CH_0:  TRISAbits.TRISA0 = 1; ANSELbits.ANS0   = 1; break;
        case ADC_CH_1:  TRISAbits.TRISA1 = 1; ANSELbits.ANS1   = 1; break;
        case ADC_CH_2:  TRISAbits.TRISA2 = 1; ANSELbits.ANS2   = 1; break;
        case ADC_CH_3:  TRISAbits.TRISA3 = 1; ANSELbits.ANS3   = 1; break;
        case ADC_CH_4:  TRISAbits.TRISA5 = 1; ANSELbits.ANS4   = 1; break;
        case ADC_CH_5:  TRISEbits.TRISE0 = 1; ANSELbits.ANS5   = 1; break;
        case ADC_CH_6:  TRISEbits.TRISE1 = 1; ANSELbits.ANS6   = 1; break;
        case ADC_CH_7:  TRISEbits.TRISE2 = 1; ANSELbits.ANS7   = 1; break;
        case ADC_CH_8:  TRISBbits.TRISB2 = 1; ANSELHbits.ANS8  = 1; break;
        case ADC_CH_9:  TRISBbits.TRISB3 = 1; ANSELHbits.ANS9  = 1; break;
        case ADC_CH_10: TRISBbits.TRISB1 = 1; ANSELHbits.ANS10 = 1; break;
        case ADC_CH_11: TRISBbits.TRISB4 = 1; ANSELHbits.ANS11 = 1; break;
        case ADC_CH_12: TRISBbits.TRISB0 = 1; ANSELHbits.ANS12 = 1; break;
        case ADC_CH_13: TRISBbits.TRISB5 = 1; ANSELHbits.ANS13 = 1; break;
        default: break; 
    }
}

void HAL_ADC_StartConversion(adc_channel_t ch) {
    /* 1. Select ADC Input Channel */
    ADCON0 = (ADCON0 & 0xC3) | (uint8_t)((ch & 0x0F) << 2);

    /* 2. Wait the required acquisition time (Tacq) for Chold to charge */
    __delay_us(20);

    /* 3. Register the active channel for the ISR to know where to save data */
    current_adc_channel = (uint8_t)ch;

    /* 4. Start conversion */
    ADCON0bits.GO_nDONE = 1;
}

uint16_t HAL_ADC_GetResult(adc_channel_t ch) {
    uint16_t val;
    
    /* CRITICAL SECTION: Disable global interrupt temporarily.
     * Prevents data tearing if an interrupt occurs while reading 
     * a 16-bit variable on an 8-bit architecture.
     */
    INTCONbits.GIE = 0;  
    val = adc_channel_values[ch];
    INTCONbits.GIE = 1;  
    
    return val;
}

void HAL_ADC_ISR_Handler(void) {
    /* Check if the interrupt was triggered by the ADC module */
    if (PIR1bits.ADIF == 1) {
        
        /* Read the 10-bit result from hardware registers */
        uint16_t adc_raw = ((uint16_t)((ADRESH << 8) | ADRESL));
        
        /* Save the result to the corresponding index in the array */
        if (current_adc_channel < 14) {
            adc_channel_values[current_adc_channel] = adc_raw;
        }
        
        /* Reset state machine to Idle and clear hardware flag */
        current_adc_channel = 14; 
        PIR1bits.ADIF = 0; 
    }
}