/**
 * @file    hal_adc.h
 * @author  Tran Gia Khang
 * @brief   Hardware Abstraction Layer for 10-bit ADC on PIC16F887.
 * @details Implemented according to Microchip Datasheet DS41291D.
 * Supports interrupt-driven (non-blocking) conversions.
 * @version 1.2
 */

#ifndef HAL_ADC_H
#define HAL_ADC_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Enumeration for all available ADC Channels (AN0 to AN13).
 */
typedef enum {
    ADC_CH_0 = 0b0000,   /*!< AN0  - RA0 */
    ADC_CH_1 = 0b0001,   /*!< AN1  - RA1 */
    ADC_CH_2 = 0b0010,   /*!< AN2  - RA2 */
    ADC_CH_3 = 0b0011,   /*!< AN3  - RA3 */
    ADC_CH_4 = 0b0100,   /*!< AN4  - RA5 */
    ADC_CH_5 = 0b0101,   /*!< AN5  - RE0 */
    ADC_CH_6 = 0b0110,   /*!< AN6  - RE1 */
    ADC_CH_7 = 0b0111,   /*!< AN7  - RE2 */
    ADC_CH_8 = 0b1000,   /*!< AN8  - RB2 */
    ADC_CH_9 = 0b1001,   /*!< AN9  - RB3 */
    ADC_CH_10= 0b1010,   /*!< AN10 - RB1 */
    ADC_CH_11= 0b1011,   /*!< AN11 - RB4 */
    ADC_CH_12= 0b1100,   /*!< AN12 - RB0 */
    ADC_CH_13= 0b1101    /*!< AN13 - RB5 */
} adc_channel_t;

/**
 * @brief ADC Clock Conversion Source.
 */
typedef enum {
    ADC_CLK_FOSC_2  = 0b00, /*!< FOSC/2  */
    ADC_CLK_FOSC_8  = 0b01, /*!< FOSC/8 (Recommended for 4MHz) */
    ADC_CLK_FOSC_32 = 0b10, /*!< FOSC/32 */
    ADC_CLK_FRC     = 0b11  /*!< FRC (Internal Oscillator) */
} adc_clock_t;

/**
 * @brief ADC Voltage Reference selection.
 */
typedef enum {
    ADC_VREF_INTERNAL = 0,  /*!< VREF+ = VDD, VREF- = VSS */
    ADC_VREF_EXTERNAL = 1   /*!< VREF+ = RA3, VREF- = RA2 */
} adc_vref_t;

/* ==============================================================================
 * API FUNCTION PROTOTYPES
 * ============================================================================== */

void HAL_ADC_Init(adc_clock_t clk, adc_vref_t vref);
void HAL_ADC_ConfigChannel(adc_channel_t ch);
void HAL_ADC_StartConversion(adc_channel_t ch);
uint16_t HAL_ADC_GetResult(adc_channel_t ch);

/**
 * @brief  ADC Interrupt Service Routine Handler.
 * @note   Must be called inside the global __interrupt() function.
 */
void HAL_ADC_ISR_Handler(void);

#endif /* HAL_ADC_H */