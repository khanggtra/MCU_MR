#include "../sys/sys_config/sys_config.h"
#include "../sys/sys_tick/sys_tick.h"
#include "../hal/hal_gpio/hal_gpio.h"
#include "../hal/hal_uart/hal_uart.h"
#include "../hal/hal_adc/hal_adc.h"
#include <stdint.h>
#include <stdbool.h>


typedef enum {
    MODE_POTENTIOMETER = 0, 
    OVERRIDE_RED,           
    OVERRIDE_GREEN,        
    OVERRIDE_YELLOW       
} system_mode_t;

int main(void) {

    sys_config();
    HAL_ADC_Init(); 

    HAL_GPIO_SetDirection(PORT_D, PIN_4, GPIO_DIR_OUTPUT); 
    HAL_GPIO_SetDirection(PORT_D, PIN_5, GPIO_DIR_OUTPUT); 
    HAL_GPIO_SetDirection(PORT_D, PIN_6, GPIO_DIR_OUTPUT); 

    HAL_GPIO_SetDirection(PORT_B, PIN_3, GPIO_DIR_INPUT);  
    HAL_GPIO_PullUpEnable(PIN_3);
    HAL_GPIO_SetDirection(PORT_B, PIN_4, GPIO_DIR_INPUT);  
    HAL_GPIO_PullUpEnable(PIN_4);
    HAL_GPIO_SetDirection(PORT_B, PIN_5, GPIO_DIR_INPUT);  
    HAL_GPIO_PullUpEnable(PIN_5);

    system_mode_t current_mode = MODE_POTENTIOMETER;
    uint32_t override_start_time = 0;
    uint32_t last_uart_send_time = 0;

    uint16_t adc_raw = 0;
    uint8_t pot_duty_cycle = 0; 
    uint32_t last_pwm_tick = 0;
    uint8_t pwm_counter = 0;   


    bool p_bt1 = true, p_bt2 = true, p_bt3 = true;

    while (1) {
        uint32_t current_ms = SysTick_GetMs();

        /* =========================================================================
         * LUỒNG 1: GIAO TIẾP MATLAB GUI & ĐỌC ADC (200ms gửi 1 lần)
         * ========================================================================= */
        if ((current_ms - last_uart_send_time) >= 200) {
            last_uart_send_time = current_ms;


            adc_raw = HAL_ADC_Read(12);


            pot_duty_cycle = (uint8_t)((adc_raw * 100UL) / 1023);


            uint32_t voltage_mV = (adc_raw * 5000UL) / 1023;
            uint32_t volts = voltage_mV / 1000;
            uint32_t decivolts = (voltage_mV % 1000) / 10; /* Lấy 2 chữ số thập phân */

            HAL_UART_WriteString("ADC:");
            HAL_UART_WriteInt(adc_raw);
            HAL_UART_WriteString(",V:");
            HAL_UART_WriteInt(volts);
            HAL_UART_WriteChar('.');
            if (decivolts < 10) HAL_UART_WriteChar('0'); /* Thêm số 0 nếu dưới 0.10V */
            HAL_UART_WriteInt(decivolts);
            HAL_UART_WriteString("\r\n");
        }

        /* =========================================================================
         * LUỒNG 2: XỬ LÝ NÚT NHẤN CAN THIỆP & KHÓA CHÉO CÓ NGẮT (INTERRUPT)
         * ========================================================================= */
        bool c_bt1 = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
        bool c_bt2 = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
        bool c_bt3 = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);

        if (c_bt1 && !p_bt1) {
            current_mode = OVERRIDE_RED;
            override_start_time = current_ms; 
        } 
        else if (c_bt2 && !p_bt2) {
            current_mode = OVERRIDE_GREEN;
            override_start_time = current_ms;
        } 
        else if (c_bt3 && !p_bt3) {
            current_mode = OVERRIDE_YELLOW;
            override_start_time = current_ms;
        }

        p_bt1 = c_bt1; p_bt2 = c_bt2; p_bt3 = c_bt3;

        if (current_mode != MODE_POTENTIOMETER) {
            if ((current_ms - override_start_time) >= 5000) {
                current_mode = MODE_POTENTIOMETER; /* Hết 5s -> Trả về cho biến trở */
            }
        }

        /* =========================================================================
         * LUỒNG 3: SOFTWARE PWM ĐIỀU KHIỂN ĐỘ SÁNG LED (Tần số ~100Hz)
         * Mỗi bước đếm PWM mất 0.1ms (100us) -> 1 chu kỳ 100 bước mất 10ms
         * ========================================================================= */
        if ((current_ms - last_pwm_tick) >= 1) { 
            last_pwm_tick = current_ms;
            pwm_counter += 10;
            if (pwm_counter >= 100) pwm_counter = 0;
        }

        uint8_t duty_red = 0, duty_green = 0, duty_yellow = 0;

        switch (current_mode) {
            case MODE_POTENTIOMETER:
                duty_red    = pot_duty_cycle;
                duty_green  = pot_duty_cycle;
                duty_yellow = pot_duty_cycle;
                break;

            case OVERRIDE_RED:
                duty_red    = 100;
                duty_green  = 0;
                duty_yellow = 0;
                break;

            case OVERRIDE_GREEN:
                duty_red    = 0;
                duty_green  = 100;
                duty_yellow = 0;
                break;

            case OVERRIDE_YELLOW:
                duty_red    = 0;
                duty_green  = 0;
                duty_yellow = 100;
                break;
        }

        HAL_GPIO_WritePin(PORT_D, PIN_4, (pwm_counter < duty_red)    ? GPIO_HIGH : GPIO_LOW);
        HAL_GPIO_WritePin(PORT_D, PIN_5, (pwm_counter < duty_green)  ? GPIO_HIGH : GPIO_LOW);
        HAL_GPIO_WritePin(PORT_D, PIN_6, (pwm_counter < duty_yellow) ? GPIO_HIGH : GPIO_LOW);
    }
}