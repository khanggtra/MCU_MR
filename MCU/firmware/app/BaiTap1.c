#include "../sys/sys_config/sys_config.h"
#include "../sys/sys_tick/sys_tick.h"
#include "../hal/hal_gpio/hal_gpio.h"
#include "../hal/hal_uart/hal_uart.h"
#include "app_commute/app_commute.h"
#include <stdint.h>
#include <stdbool.h>

int main(void) {
    /* 1. Khởi tạo toàn bộ hệ thống phần cứng */
    sys_config();

    /* 2. Cấu hình Data Direction cho 3 LED (Output) và mặc định tắt */
    HAL_GPIO_SetDirection(PORT_D, PIN_4, GPIO_DIR_OUTPUT); /* RD4 - Đỏ */
    HAL_GPIO_SetDirection(PORT_D, PIN_5, GPIO_DIR_OUTPUT); /* RD5 - Xanh */
    HAL_GPIO_SetDirection(PORT_D, PIN_6, GPIO_DIR_OUTPUT); /* RD6 - Vàng */

    HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW);

    /* 3. Cấu hình Data Direction & Pull-up cho 3 Nút nhấn (Input) */
    HAL_GPIO_SetDirection(PORT_B, PIN_3, GPIO_DIR_INPUT); /* RB3 - BT1 (Đỏ) */
    HAL_GPIO_PullUpEnable(PIN_3);

    HAL_GPIO_SetDirection(PORT_B, PIN_4, GPIO_DIR_INPUT); /* RB4 - BT2 (Xanh) */
    HAL_GPIO_PullUpEnable(PIN_4);

    HAL_GPIO_SetDirection(PORT_B, PIN_5, GPIO_DIR_INPUT); /* RB5 - BT3 (Vàng) */
    HAL_GPIO_PullUpEnable(PIN_5);

    /* 4. Vòng lặp chính vô tận (Main Loop) */
    while (1) {

        /* =========================================================================
         * YÊU CẦU 1.1: Nhấn nút Xanh (RB4) LED Xanh (RD5) sáng. Thả ra LED tắt.
         * ========================================================================= */
        {
            if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
                HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH);
            } else {
                HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
            }
        }


        // /* =========================================================================
        //  * YÊU CẦU 1.2: Nhấn nút Xanh, LED Xanh sáng 5s tự tắt (Non-blocking)
        //  * ========================================================================= */
        // TH1: có can thiệp
        // {
        //     static uint32_t start_time = 0;
        //     static bool led_is_on = false;
        //     static bool prev_btn = true; /* true = HIGH (chưa nhấn) */
        // 
        //     bool curr_btn = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        // 
        //     if (curr_btn && !prev_btn) {
        //         led_is_on = true;
        //         start_time = SysTick_GetMs();
        //         HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH);
        //     }
        //     prev_btn = curr_btn;
        // 
        //     /* Kiểm tra thời gian 5000ms (5 giây) */
        //     if (led_is_on && ((SysTick_GetMs() - start_time) >= 5000)) {
        //         led_is_on = false;
        //         HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
        //     }
        // }




        

        //TH2: KHÔNG CAN THIỆP
        // {
        //     static uint32_t start_time = 0;
        //     static bool led_is_on = false;
        //     static bool prev_btn = true; /* true = HIGH (chưa nhấn) */
        // 
        //     bool curr_btn = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        // 
        //     if (curr_btn && !prev_btn){
        //          if (!led_is_on) {
        //              led_is_on = true;
        //              start_time = SysTick_GetMs();
        //              HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH);
        //          }
        //     }
        //     prev_btn = curr_btn;
        // 
        //     /* Kiểm tra thời gian 5000ms (5 giây) */
        //     if (led_is_on && ((SysTick_GetMs() - start_time) >= 5000)) {
        //         led_is_on = false;
        //         HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
        //     }
        // }

        // /* =========================================================================
        //  * YÊU CẦU 2.1: 3 LED, 3 Nút nhấn độc lập + KHÓA CHÉO (Interlock)
        //  * ========================================================================= */
        // {
        //     static uint8_t lock_state = 0; /* 0: NONE, 1: RED(RB3), 2: GREEN(RB4), 3: YELLOW(RB5) */
        // 
        //     bool bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //     bool bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //     bool bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        // 
        //     switch (lock_state) {
        //         case 0: /* Tự do */
        //             if (bt1) { 
        //                  lock_state = 1; 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_HIGH); 
        //              }
        //             else if (bt2) { 
        //                  lock_state = 2; 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH); 
        //              }
        //             else if (bt3) { 
        //                  lock_state = 3; 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_HIGH); }
        //             break;
        //         case 1: /* RB3 đang khóa */
        //             if (!bt1) { 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW); 
        //                  lock_state = 0; 
        //             }
        //             break;
        //         case 2: /* RB4 đang khóa */
        //             if (!bt2) { 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW); 
        //                  lock_state = 0; 
        //             }
        //             break;
        //         case 3: /* RB5 đang khóa */
        //             if (!bt3) { 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW); 
        //                  lock_state = 0; 
        //             }
        //             break;
        //         default:
        //             lock_state = 0;
        //             break;
        //     }
        // }


       // /* =========================================================================
        //  * YÊU CẦU 2.2: 3 LED, 3 Nút nhấn, sáng 5 giây tự tắt + KHÓA CHÉO (Interlock)
        //  * ========================================================================= */
        // TH1: CÓ CAN THIỆP
        // {
        //     static uint8_t lock_state = 0; /* 0: Tự do, 1: Đỏ (RB3), 2: Xanh (RB4), 3: Vàng (RB5) */
        //     static uint32_t start_time = 0;
        //     static bool p_bt1 = true, p_bt2 = true, p_bt3 = true; /* Trạng thái nút trước đó (HIGH = chưa nhấn) */
        // 
        //     /* Đọc trạng thái nút nhấn hiện tại (Active LOW) */
        //     bool c_bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //     bool c_bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //     bool c_bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        // 
        //     switch (lock_state) {
        //         case 0: /* Tự do - Chưa có LED nào sáng */
        //             if (c_bt1 && !p_bt1) {    
        //                 lock_state = 1;
        //                 start_time = SysTick_GetMs();
        //                 HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_HIGH); /* Bật LED Đỏ */
        //             } 
        //             else if (c_bt2 && !p_bt2) { 
        //                 lock_state = 2;
        //                 start_time = SysTick_GetMs();
        //                 HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH); /* Bật LED Xanh */
        //             } 
        //             else if (c_bt3 && !p_bt3) { 
        //                 lock_state = 3;
        //                 start_time = SysTick_GetMs();
        //                 HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_HIGH); /* Bật LED Vàng */
        //             }
        //             break;
        // 
        //         case 1: /* LED Đỏ (RB3) đang sáng - Khóa RB4 và RB5 */
        //             if (c_bt1 && !p_bt1) {
        //                 start_time = SysTick_GetMs();
        //             }
        // 
        //             /* Kiểm tra hết thời gian 5 giây (5000 ms) */
        //             if ((SysTick_GetMs() - start_time) >= 5000) {
        //                 HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW); 
        //                 lock_state = 0;                           
        //             }
        //             break;
        // 
        //         case 2: 
        //             if (c_bt2 && !p_bt2) {
        //                 start_time = SysTick_GetMs(); 
        //             }
        //             if ((SysTick_GetMs() - start_time) >= 5000) {
        //                 HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW); 
        //                 lock_state = 0;
        //             }
        //             break;
        // 
        //         case 3: 
        //             if (c_bt3 && !p_bt3) {
        //                 start_time = SysTick_GetMs(); 
        //             }
        //             if ((SysTick_GetMs() - start_time) >= 5000) {
        //                 HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW); 
        //                 lock_state = 0;
        //             }
        //             break;
        // 
        //         default:
        //             lock_state = 0;
        //             break;
        //     }
        // 
        //     p_bt1 = c_bt1;
        //     p_bt2 = c_bt2;
        //     p_bt3 = c_bt3;
        // }

            
        
        
        
        
        // TH2: KHÔNG CAN THIỆP
        // {
        //     static uint8_t lock_state = 0; /* 0: Tự do, 1: Đỏ (RB3), 2: Xanh (RB4), 3: Vàng (RB5) */
        //     static uint32_t start_time = 0;
        //     static bool p_bt1 = true, p_bt2 = true, p_bt3 = true; /* Trạng thái nút trước đó (HIGH = chưa nhấn) */
        // 
        //     /* Đọc trạng thái nút nhấn hiện tại (Active LOW) */
        //     bool c_bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //     bool c_bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //     bool c_bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        // 
        //     switch (lock_state) {
        //         case 0: /* Tự do - Chưa có LED nào sáng */
        //             if (c_bt1 && !p_bt1) {    
        //                 lock_state = 1;
        //                 start_time = SysTick_GetMs();
        //                 HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_HIGH); /* Bật LED Đỏ */
        //             } 
        //             else if (c_bt2 && !p_bt2) { 
        //                 lock_state = 2;
        //                 start_time = SysTick_GetMs();
        //                 HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH); /* Bật LED Xanh */
        //             } 
        //             else if (c_bt3 && !p_bt3) { 
        //                 lock_state = 3;
        //                 start_time = SysTick_GetMs();
        //                 HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_HIGH); /* Bật LED Vàng */
        //             }
        //             break;
        // 
        //         case 1: /* LED Đỏ (RB3) đang sáng - Khóa RB4 và RB5 */
        // 
        //             /* Kiểm tra hết thời gian 5 giây (5000 ms) */
        //             if ((SysTick_GetMs() - start_time) >= 5000) {
        //                 HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW); 
        //                 lock_state = 0;                           
        //             }
        //             break;
        // 
        //         case 2: 
        //             if ((SysTick_GetMs() - start_time) >= 5000) {
        //                 HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW); 
        //                 lock_state = 0;
        //             }
        //             break;
        // 
        //         case 3: 
        //             if ((SysTick_GetMs() - start_time) >= 5000) {
        //                 HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW); 
        //                 lock_state = 0;
        //             }
        //             break;
        // 
        //         default:
        //             lock_state = 0;
        //             break;
        //     }
        // 
        //     p_bt1 = c_bt1;
        //     p_bt2 = c_bt2;
        //     p_bt3 = c_bt3;
        // }
    }
}