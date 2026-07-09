#include "../sys/sys_config/sys_config.h"
#include "../sys/sys_tick/sys_tick.h"
#include "../hal/hal_gpio/hal_gpio.h"
#include "../hal/hal_uart/hal_uart.h"

#include "app_commute/app_commute.h"
#include <stdint.h>


int main(void) {
    sys_config();
    //Set the initial state of the LEDs to OFF
    HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);

    uint32_t t_start = SysTick_GetMs();
    uint32_t elapsed_time = 0;
    while (1) {
        if(SysTick_GetMs() - t_start >= 100) {
            t_start = SysTick_GetMs(); // Reset the start time
            if(HAL_GPIO_ReadPin(PORT_B, PIN_0) == GPIO_LOW) {
                HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_HIGH); // Turn on Green LED
            }
            else {
                HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW); // Turn off Green LED
            }
        }
        
    }
    return 0;
}
