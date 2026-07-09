/*L298n driver and GA25 motor*/

#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include <xc.h>
#include "../../hal/hal_gpio/hal_gpio.h"


void DC_Motor_Init(gpio_port_t IN_port, gpio_pin_t IN1_pin, gpio_pin_t IN2_pin);
void DC_Motor_SetDutyCycle(int32_t duty_cycle); // Duty cycle in millivolts, range: -1000 to 1000
void DC_Motor_Brake(void);

#endif