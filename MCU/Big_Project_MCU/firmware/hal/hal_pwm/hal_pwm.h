#ifndef HAL_PWM_H
#define HAL_PWM_H

#include <xc.h>
#include <stdint.h>

/* Define PWM channels for PIC16F887 */
typedef enum {
    PWM_CHANNEL_1 = 1, /* CCP1 module - Output on pin RC2 */
    PWM_CHANNEL_2 = 2  /* CCP2 module - Output on pin RC1 */
} PWM_Channel_t;

/**
 * @brief  Initializes the PWM module on both CCP1 and CCP2 channels.
 * @param  frequency: Desired PWM frequency in Hertz (Hz).
 *         Recommended for DC motors: 5000Hz (5kHz) to 10000Hz (10kHz).
 */
void HAL_PWM_Init(uint32_t frequency);

/**
 * @brief  Sets the Duty Cycle for a specific PWM channel.
 * @param  channel: Target PWM channel (PWM_CHANNEL_1 or PWM_CHANNEL_2).
 * @param  duty_permille: Duty cycle expressed in permille (0 - 1000).
 *         Example: 0 = 0.0%, 500 = 50.0%, 1000 = 100.0%.
 */
void HAL_PWM_SetDutyCycle(PWM_Channel_t channel, uint16_t duty_permille);

#endif /* HAL_PWM_H */