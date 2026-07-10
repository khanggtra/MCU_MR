#include "../sys/sys_config/sys_config.h"
#include "../sys/sys_tick/sys_tick.h"
#include "../hal/hal_gpio/hal_gpio.h"
#include "../hal/hal_uart/hal_uart.h"

#include "app_commute/app_commute.h"
#include <stdint.h>


int main(void) {

    // /*1.1*/Nhấn nút nhấn, đèn Led sáng. Thả nút nhấn, đèn Led tắt.
    sys_config();
    HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
    while (1) {
        if (HAL_GPIO_ReadPin(PORT_B, PIN_1) == GPIO_LOW) {
            HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH); 
        } else {
            HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);  
        }
    }
    
    
    
    // /*1.2*/Nhấn nút nhấn, đèn Led sáng, 5 giây sau đèn Led tự tắt ( Có 2 trường hợp phụ).
    // sys_config();
    // //Set the initial state of the LEDs to OFF
    // HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW);
    // HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_LOW);
    // HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);

    // uint32_t t_start = SysTick_GetMs();
    // uint32_t elapsed_time = 0;
    // while (1) {
    //     if(SysTick_GetMs() - t_start >= 100) { 
    //         t_start = SysTick_GetMs(); // Reset the start time
    //         elapsed_time = 0; //Reset the elapsed time
    //         if(HAL_GPIO_ReadPin(PORT_B, PIN_0) == GPIO_LOW) {
    //             HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_HIGH); // Turn on Green LED
    //         }
    //         else {
    //             HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW); // Turn off Green LED
    //         }
    //     }
        
    // }
    // return 0;
    

    // /*2.1*/Dùng VĐK kết nối 3 đèn Led – Xanh, Vàng, Đỏ, kết nối 3 nút nhấn cho 3 đèn và làm lại như phần 1.1 cho mỗi đèn Xanh, Vàng, Đỏ độc lập
    // HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW); // Xanh
    // HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_LOW); // Vàng
    // HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW); // Đỏ

    // while (1) {
    //     // --- Xử lý Cụm 1: Nút Xanh (B0) điều khiển LED Xanh (D0) ---
    //     if (HAL_GPIO_ReadPin(PORT_B, PIN_0) == GPIO_LOW) {
    //         HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_HIGH);
    //     } else {
    //         HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW);
    //     }

    //     // --- Xử lý Cụm 2: Nút Vàng (B1) điều khiển LED Vàng (D1) ---
    //     if (HAL_GPIO_ReadPin(PORT_B, PIN_1) == GPIO_LOW) {
    //         HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_HIGH);
    //     } else {
    //         HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_LOW);
    //     }

    //     // --- Xử lý Cụm 3: Nút Đỏ (B2) điều khiển LED Đỏ (D2) ---
    //     if (HAL_GPIO_ReadPin(PORT_B, PIN_2) == GPIO_LOW) {
    //         HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
    //     } else {
    //         HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
    //     }
    // }
    // */

    // return 0;


    // /*2.2*/Dùng VĐK kết nối 3 đèn Led – Xanh, Vàng, Đỏ, kết nối 3 nút nhấn cho 3 đèn và làm lại như phần 1.2 cho mỗi đèn Xanh, Vàng, Đỏ độc lập
    // sys_config();
    // //Set the initial state of the LEDs to OFF
    // HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW);
    // HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_LOW);
    // HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);

    // uint32_t t_start = SysTick_GetMs();
    // uint8_t current_step = 0;

    // uint8_t LED1_state = 0; // 0: OFF, 1: ON
    // uint8_t LED2_state = 0;

    // uint32_t LED1_timer = 0;
    // uint32_t LED2_timer = 0;

    // uint32_t LED1_counter = 0;
    // uint32_t LED2_counter = 0;

    // while (1) {
    //     if(SysTick_GetMs() - t_start >= 10 && current_step == 0) { 
    //         if(HAL_GPIO_ReadPin(PORT_B, PIN_1) == GPIO_LOW && LED1_state == 0) {
    //             LED1_timer = SysTick_GetMs(); // Start the timer for LED1
    //             HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_HIGH); // Turn on Green LED
    //             LED1_state = 1;
    //         }
    //         current_step = 1; // Move to the next step
    //     }
    //     else if(SysTick_GetMs() - t_start > 20 && current_step == 1) {
    //         if(HAL_GPIO_ReadPin(PORT_B, PIN_2) == GPIO_LOW) {
    //             LED2_timer = SysTick_GetMs(); // Start the timer for LED2
    //             HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_HIGH); // Turn on Yellow LED
    //             LED2_state = 1;
    //         }
    //         current_step = 2; // Move to the next step
    //     }
    //     else if(SysTick_GetMs() - t_start > 30 && current_step == 2) {
    //         if(LED1_state == 1){
    //             LED1_counter = SysTick_GetMs() - LED1_timer; // Start counting for LED1
    //             if(LED1_counter >= 5000) {
    //                 HAL_GPIO_WritePin(PORT_D, PIN_0, GPIO_LOW); // Turn off Green LED
    //                 LED1_state = 0; // Reset LED1 state
    //             }
    //         }

    //         if(LED2_state == 1){
    //             LED2_counter = SysTick_GetMs() - LED2_timer; // Start counting for LED2
    //             if(LED2_counter >= 5000) {
    //                 HAL_GPIO_WritePin(PORT_D, PIN_1, GPIO_LOW); // Turn off Yellow LED
    //                 LED2_state = 0; // Reset LED2 state
    //             }
    //         }
    //         current_step = 3; // Move to the next step
    //     }
        
    //     else if(SysTick_GetMs() - t_start > 100) {
    //         t_start = SysTick_GetMs(); // Reset the start time
    //         current_step = 0; // Reset to the first step
    //     }
        
    // }
    // return 0;
}
