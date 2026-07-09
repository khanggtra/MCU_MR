/**
 * @file main.c
 * @author pc
 * @date 2026-04-27
 * @brief Main function
 */
#include "../sys/sys_config/sys_config.h"
#include "../sys/sys_tick/sys_tick.h"
#include "../hal/hal_gpio/hal_gpio.h"
#include "../hal/hal_uart/hal_uart.h"

#include "../drivers/Encoder/encoder.h"
#include "../drivers/DC motor/DC_Motor.h"

#include "../utils/utils_pid/utils_pid.h"
#include "app_commute/app_commute.h"
#include <stdint.h>

#include "../hal/hal_pwm/hal_pwm.h"

#define MOTOR_SPEED_CALIB 500  /* Calibration value for motor speed */

int main(void) {
    OSCCON = 0x71;
    sys_config();
    /* Local Timing Variables */
    uint32_t t_start = SysTick_GetMs();
    
    uint32_t elapsed_time = 0;
    uint8_t step_count = 0;
    
    int32_t Motor_angle;                                                                                                                                                                                                                                                     

    PID_Controller pid_motor;
    PID_Init(&pid_motor, 81920, 0, 0, 10, -1000, 1000); /*10^-1 duty cycle */

    int32_t duty_cycle_pid_mV;
    int32_t setpoint = 180; /* Desired angle in 10^-1 degrees */


    DC_Motor_Init(PORT_D, PIN_0, PIN_1);

    Encoder_Init(PIN_0, PIN_1);
    uint8_t Run_mode = 1; /* 0: Idle, 1: Active */
    uint8_t Calib_done = 0;

    uint32_t t_start_commute = 0; /* Timer for managing APP_Commute calls */
    uint32_t commute_interval = 100; /* Interval in ms for calling APP_Commute */
    HAL_PWM_SetDutyCycle(PWM_CHANNEL_1, 0);
    HAL_GPIO_SetDirection(PORT_D, PIN_4, GPIO_DIR_INPUT);
    
    HAL_UART_WriteString("System Initialized. Starting Calibration...\n");
    while (1) {   
        DC_Motor_SetDutyCycle(MOTOR_SPEED_CALIB); 
    //     /* ---------------------------------------------------
    //      * 1. CHẾ ĐỘ CALIBRATION (Chỉ chạy lúc khởi động)
    //      * --------------------------------------------------- */
    //     while (!Calib_done) {
    //         elapsed_time = SysTick_GetMs() - t_start;
    //         if(elapsed_time < 100) {
    //             continue; 
    //         }
    //         if(HAL_GPIO_ReadPin(PORT_D, PIN_4) == GPIO_LOW) { 
    //             Calib_done = 1; 
    //             DC_Motor_SetDutyCycle(0); 
    //             Encoder_Reset(); 
    //             Run_mode = 1; 
                
    //             HAL_UART_WriteString("Calibration Complete. Entering Active Mode lan2...\n");
                
    //             /* RESET LẠI TOÀN BỘ TIMER TRƯỚC KHI VÀO CHẠY PID */
    //             t_start = SysTick_GetMs();
    //             t_start_commute = SysTick_GetMs();
    //             break;
    //         }
    //         DC_Motor_SetDutyCycle(MOTOR_SPEED_CALIB); 
    //     }
            
    //     /* ---------------------------------------------------
    //      * 2. CHẾ ĐỘ HOẠT ĐỘNG CHÍNH (Run_mode)
    //      * --------------------------------------------------- */
    //     if (Run_mode == 1) {
            
    //         /* TASK 1: Chạy thuật toán PID đúng chu kỳ 10ms */
    //         if (SysTick_GetMs() - t_start >= 10) {
    //             t_start = SysTick_GetMs(); /* Reset timer ngay lập tức */
                
    //             Motor_angle = Encoder_GetAngle();
    //             duty_cycle_pid_mV = PID_Compute(&pid_motor, setpoint, Motor_angle);
    //             DC_Motor_SetDutyCycle(duty_cycle_pid_mV);
    //         }

    //         /* TASK 2: Giao tiếp UART & Cập nhật trạng thái (100ms) */
    //         if (SysTick_GetMs() - t_start_commute >= commute_interval) {
    //             t_start_commute = SysTick_GetMs(); /* Reset timer */
                
    //             APP_Commute(&pid_motor, Motor_angle, &setpoint, &Run_mode, &Calib_done);
    //         }
    //     }
    }
    return 0;
}
