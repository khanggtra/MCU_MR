#include "hal_pwm.h"
#include "../../project_config/project_config.h" // Required for _XTAL_FREQ definition

// Internal variable to store the maximum 10-bit duty cycle value 
// corresponding to the current frequency.
static uint16_t pwm_max_duty = 0;

void HAL_PWM_Init(uint32_t frequency) {
    /* 1. Configure pins RC1 (CCP2) and RC2 (CCP1) as Digital Outputs */
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
    
    /* Ensure outputs are LOW at initialization for motor safety */
    PORTCbits.RC1 = 0;
    PORTCbits.RC2 = 0;

    /* 2. Configure CCP1 and CCP2 modules for PWM mode */
    // Bit 3-0 = 1100: PWM mode, PxA, PxC active-high; PxB, PxD active-high
    CCP1CON = 0x0C; 
    CCP2CON = 0x0C; 

    /* 3. Timer2 configuration for the target PWM frequency */
    // Use Prescaler = 16 to cover a wide frequency range 
    // (~1kHz to ~20kHz with an 8MHz crystal)
    T2CONbits.T2CKPS = 0b00; // Prescaler = 1 (no prescaling)
    
    // Apply PR2 calculation formula: PR2 = (FOSC / (4 * F_PWM * Prescale)) - 1
    // Use integer arithmetic and careful type casting to prevent overflow
    uint32_t pr2_calc = (_XTAL_FREQ / (frequency * 4 * 1)) - 1;
    
    // Safety limit for the 8-bit PR2 register
    if (pr2_calc > 255) pr2_calc = 255;
    PR2 = (uint8_t)pr2_calc;

    /* 4. Calculate and store the maximum 10-bit Duty Cycle resolution */
    // Max Duty = 4 * (PR2 + 1)
    pwm_max_duty = (uint16_t)(4 * (PR2 + 1));

    /* 5. Clear duty cycle registers and enable Timer 2 */
    CCPR1L = 0;
    CCPR2L = 0;
    T2CONbits.TMR2ON = 1; // Start PWM generation
}

void HAL_PWM_SetDutyCycle(PWM_Channel_t channel, uint16_t duty_permille) {
    /* Clamp the input to the safe permille range (0 - 1000) */
    if (duty_permille > 1000) duty_permille = 1000;
    
    /* Convert the permille ratio (0-1000) to the actual 10-bit hardware value */
    // Formula: PWM_Value = (duty_permille * Max_Duty) / 1000
    uint32_t duty_val_32 = ((uint32_t)duty_permille * pwm_max_duty) / 1000;
    uint16_t duty_val = (uint16_t)duty_val_32;

    /* Load into registers: 
     * - The 8 Most Significant Bits (MSBs) go into CCPRxL 
     * - The 2 Least Significant Bits (LSBs) go into bits 5 and 4 of CCPxCON 
     */
    if (channel == PWM_CHANNEL_1) {
        CCPR1L = (uint8_t)(duty_val >> 2);
        CCP1CONbits.DC1B1 = (duty_val & 0x02) ? 1 : 0;
        CCP1CONbits.DC1B0 = (duty_val & 0x01) ? 1 : 0;
    } 
    else if (channel == PWM_CHANNEL_2) {
        CCPR2L = (uint8_t)(duty_val >> 2);
        CCP2CONbits.DC2B1 = (duty_val & 0x02) ? 1 : 0;
        CCP2CONbits.DC2B0 = (duty_val & 0x01) ? 1 : 0;
    }
}