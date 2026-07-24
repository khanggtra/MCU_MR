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
    HAL_GPIO_SetDirection(PORT_D, PIN_2, GPIO_DIR_OUTPUT); /* RD2 - Đỏ */
    HAL_GPIO_SetDirection(PORT_D, PIN_3, GPIO_DIR_OUTPUT); /* RD3 - Xanh */
    HAL_GPIO_SetDirection(PORT_D, PIN_7, GPIO_DIR_OUTPUT); /* RD7 - Vàng */

    HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW);

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
         * YÊU CẦU 1.1: Nhấn nút Xanh (RB4) LED Xanh (RD3) sáng. Thả ra LED tắt.
         * ========================================================================= */
        {
            if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
                HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
            } else {
                HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
            }
        }


        // /* =========================================================================
        //  * YÊU CẦU 1.2: Nhấn nút Xanh, LED Xanh sáng 5s tự tắt (POLLING)
        //  * ========================================================================= */
        // // TH1: CÓ CAN THIỆP 
        // {
        //     if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
        //         HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
        //         
        //         /* Chống dội */
        //         __delay_ms(20);
        //         while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //         
        //         uint16_t time_cnt = 0;
        //         while (time_cnt < 500) {
        //             __delay_ms(10);
        //             time_cnt++;
        //             
        //             if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
        //                 time_cnt = 0; /* Reset timer đếm lại từ đầu */
        //                 
        //                 __delay_ms(20);
        //                 while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW); 
        //             }
        //         }
        //         HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
        //     }
        // }





        // // TH2: KHÔNG CAN THIỆP
        // {
        //     if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
        //         HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
        //         while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //         for (uint16_t i = 0; i < 500; i++) {
        //             __delay_ms(10);
        //         }
        //         
        //         HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
        //         
        //        
        //         
        //     }
        // }



        // /* =========================================================================
        //  * YÊU CẦU 2.1: 3 LED, 3 Nút nhấn độc lập + KHÓA CHÉO
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
        //                  HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH); 
        //              }
        //             else if (bt2) { 
        //                  lock_state = 2; 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH); 
        //              }
        //             else if (bt3) { 
        //                  lock_state = 3; 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_HIGH); }
        //             break;
        //         case 1: /* RB3 đang khóa */
        //             if (!bt1) { 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW); 
        //                  lock_state = 0; 
        //             }
        //             break;
        //         case 2: /* RB4 đang khóa */
        //             if (!bt2) { 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW); 
        //                  lock_state = 0; 
        //             }
        //             break;
        //         case 3: /* RB5 đang khóa */
        //             if (!bt3) { 
        //                  HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW); 
        //                  lock_state = 0; 
        //             }
        //             break;
        //         default:
        //             lock_state = 0;
        //             break;
        //     }
        // }


        /// /* =========================================================================
        //  * YÊU CẦU 2.2: 3 LED, 3 Nút nhấn, sáng 5 giây tự tắt + KHÓA CHÉO + POLLING
        //  * ========================================================================= */
        // // TH1: CÓ CAN THIỆP
        // {
        //     bool bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //     bool bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //     bool bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        // 
        //     if (bt1 || bt2 || bt3) {
        //         __delay_ms(20); 
        //         
        //         if (bt1 && HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
        //             HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
        //             while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //             
        //             uint16_t t1 = 0;
        //             while (t1 < 500) {
        //                 __delay_ms(10);
        //                 t1++;
        //                 if (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
        //                     t1 = 0; 
        //                     while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //                 }
        //             }
        //             HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
        //         }
        //         else if (bt2 && HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
        //             HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
        //             while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //             
        //             uint16_t t2 = 0;
        //             while (t2 < 500) {
        //                 __delay_ms(10);
        //                 t2++;
        //                 if (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
        //                     t2 = 0; 
        //                     while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //                 }
        //             }
        //             HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
        //         }
        //         else if (bt3 && HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW) {
        //             HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_HIGH);
        //             while (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        //             
        //             uint16_t t3 = 0;
        //             while (t3 < 500) {
        //                 __delay_ms(10);
        //                 t3++;
        //                 if (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW) {
        //                     t3 = 0; 
        //                     while (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        //                 }
        //             }
        //             HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW);
        //         }
        //     }
        // }



        
        // // TH2: KHÔNG CAN THIỆP 
        // {
        //     bool bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //     bool bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //     bool bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        // 
        //     if (bt1 || bt2 || bt3) {
        //         __delay_ms(20); 
        //         
        //         if (bt1 && HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW) {
        //             HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_HIGH);
        //             while (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        //             for (uint16_t i = 0; i < 500; i++) { __delay_ms(10); } /* Chờ cứng 5s */
        //             HAL_GPIO_WritePin(PORT_D, PIN_2, GPIO_LOW);
        //         }
        //         else if (bt2 && HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW) {
        //             HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_HIGH);
        //             while (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        //             for (uint16_t i = 0; i < 500; i++) { __delay_ms(10); } 
        //             HAL_GPIO_WritePin(PORT_D, PIN_3, GPIO_LOW);
        //         }
        //         else if (bt3 && HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW) {
        //             HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_HIGH);
        //             while (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);
        //             for (uint16_t i = 0; i < 500; i++) { __delay_ms(10); } 
        //             HAL_GPIO_WritePin(PORT_D, PIN_7, GPIO_LOW);
        //         }
        //     }
        // }
    }
}