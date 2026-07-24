#include "../sys/sys_config/sys_config.h"
#include "../sys/sys_tick/sys_tick.h"
#include "../hal/hal_gpio/hal_gpio.h"
#include "../hal/hal_uart/hal_uart.h"
#include "../hal/hal_adc/hal_adc.h"
#include "../hal/hal_pwm/hal_pwm.h" /* ĐÃ THÊM THƯ VIỆN PWM VÀO ĐÂY */
#include "app_commute/app_commute.h"
#include <stdint.h>
#include <stdbool.h>

/* --- NHẬN BIẾN TOÀN CỤC TỪ APP_CONTROL.C --- */
extern volatile uint8_t lock_state;
extern volatile uint32_t timer_start;
extern volatile bool pot_enabled;

/* =========================================================================
 * HÀM MAIN
 * ========================================================================= */
int main(void) {
    sys_config();
    HAL_PWM_Init(); /* Khởi tạo PWM từ thư viện HAL */
    HAL_ADC_Init();
    HAL_UART_Init(9600); 
    
    HAL_PWM_SetDuty(0); /* Ban đầu tắt PWM */

    /* Cấu hình các chân Kích cực B của NPN (RD4, RD5, RD6) làm Output và mức LOW */
    HAL_GPIO_SetDirection(PORT_D, PIN_4, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(PORT_D, PIN_5, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(PORT_D, PIN_6, GPIO_DIR_OUTPUT);
    HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW);

    HAL_GPIO_SetDirection(PORT_B, PIN_2, GPIO_DIR_INPUT); HAL_GPIO_PullUpEnable(PIN_2);
    HAL_GPIO_SetDirection(PORT_B, PIN_3, GPIO_DIR_INPUT); HAL_GPIO_PullUpEnable(PIN_3);
    HAL_GPIO_SetDirection(PORT_B, PIN_4, GPIO_DIR_INPUT); HAL_GPIO_PullUpEnable(PIN_4);
    HAL_GPIO_SetDirection(PORT_B, PIN_5, GPIO_DIR_INPUT); HAL_GPIO_PullUpEnable(PIN_5);

    IOCB |= 0x3C;           
    INTCONbits.RBIF = 0;    
    INTCONbits.RBIE = 1;   
    INTCONbits.PEIE = 1;  
    INTCONbits.GIE = 1;     

    uint32_t last_uart_time = 0;

    while (1) {
        /* ---------------------------------------------------------
         * TÁC VỤ 1: Xử lý đếm 5 giây và đọc biến trở
         * --------------------------------------------------------- */
        if (lock_state != 0) {
            /* Kiểm tra hết hạn 5 giây */
            if ((SysTick_GetMs() - timer_start) >= 5000) {
                HAL_PWM_SetDuty(0); 
                
                /* Tắt hết tất cả cực B của NPN (Ngắt mạch) */
                HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW);
                HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
                HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW);
                
                lock_state = 0;        
                pot_enabled = false;
            } 
            else {
                if (pot_enabled == true) {
                    uint16_t adc_raw = HAL_ADC_Read(0); 
                    HAL_PWM_SetDuty(adc_raw);         
                }
            }
        }

        /* ---------------------------------------------------------
         * TÁC VỤ 2: Giao tiếp UART định kỳ cho Matlab (100ms/lần)
         * --------------------------------------------------------- */
        if (SysTick_GetMs() - last_uart_time >= 100) {
            last_uart_time = SysTick_GetMs();
            
            uint16_t current_adc = HAL_ADC_Read(0);
            
            uint16_t v_int = (current_adc * 5) / 1023;
            uint16_t v_frac = ((current_adc * 500) / 1023) % 100;
        
            HAL_UART_WriteString("ADC: ");
            HAL_UART_WriteInt(current_adc);
            HAL_UART_WriteString(", VOLT: ");
            HAL_UART_WriteInt(v_int);
            HAL_UART_WriteString(".");
            if (v_frac < 10) HAL_UART_WriteString("0"); 
            HAL_UART_WriteInt(v_frac);
            HAL_UART_WriteString("\n");
        }
    }
}