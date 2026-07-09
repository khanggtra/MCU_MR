#include "DC_Motor.h"
#include "../../hal/hal_pwm/hal_pwm.h"
static gpio_port_t IN_port_static;
static gpio_pin_t IN1_pin_static;
static gpio_pin_t IN2_pin_static;

void DC_Motor_Init(gpio_port_t IN_port, gpio_pin_t IN1_pin, gpio_pin_t IN2_pin) {
    /* Configure IN1 and IN2 pins as outputs */
    IN_port_static = IN_port;
    IN1_pin_static = IN1_pin;
    IN2_pin_static = IN2_pin;

    HAL_GPIO_SetDirection(IN_port, IN1_pin, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(IN_port, IN2_pin, GPIO_DIR_OUTPUT);
    
    /* Initialize motor to stopped state (both pins LOW) */
    HAL_GPIO_WritePin(IN_port, IN1_pin, GPIO_LOW);
    HAL_GPIO_WritePin(IN_port, IN2_pin, GPIO_LOW);

    HAL_PWM_Init(10000); //Initialize PWM at 10kHz for motor control
}

void DC_Motor_SetDutyCycle(int32_t duty_cycle) {
    /* Constrain duty cycle to -1000 to 1000 */
    if (duty_cycle > 1000) duty_cycle = 1000;
    if (duty_cycle < -1000) duty_cycle = -1000;

    if (duty_cycle > 0) {
        /* Forward direction: IN1 HIGH, IN2 LOW */
        HAL_GPIO_WritePin(IN_port_static, IN1_pin_static, GPIO_HIGH);
        HAL_GPIO_WritePin(IN_port_static, IN2_pin_static, GPIO_LOW);
        uint16_t duty = (uint16_t)(duty_cycle); // Scale to 0-1000
        HAL_PWM_SetDutyCycle(PWM_CHANNEL_1, duty);

    } else if (duty_cycle < 0) {
        /* Reverse direction: IN1 LOW, IN2 HIGH */
        HAL_GPIO_WritePin(IN_port_static, IN1_pin_static, GPIO_LOW);
        HAL_GPIO_WritePin(IN_port_static, IN2_pin_static, GPIO_HIGH);
        uint16_t duty = (uint16_t)(-duty_cycle); // Scale to 0-1000
        HAL_PWM_SetDutyCycle(PWM_CHANNEL_1, duty);
    } else {
        /* Stop motor: Both pins LOW */
        HAL_GPIO_WritePin(IN_port_static, IN1_pin_static, GPIO_LOW);
        HAL_GPIO_WritePin(IN_port_static, IN2_pin_static, GPIO_LOW);
        HAL_PWM_SetDutyCycle(PWM_CHANNEL_1, 0);
    }
}

void DC_Motor_Brake(void) {
    /* Brake motor: Both pins HIGH */
    HAL_GPIO_WritePin(IN_port_static, IN1_pin_static, GPIO_HIGH);
    HAL_GPIO_WritePin(IN_port_static, IN2_pin_static, GPIO_HIGH);
    HAL_PWM_SetDutyCycle(PWM_CHANNEL_1, 0);
}