/**
 * @file    app_control.c
 * @author  Tran Gia Khang
 * @brief   Application layer control logic and Global Interrupt management.
 */
#include <xc.h>
#include "../../hal/hal_adc/hal_adc.h" /* Required to call HAL_ADC_ISR_Handler() */
#include "../../hal/hal_timer0/hal_timer0.h" /* Required to call HAL_Timer0_ISR_Handler() */
#include "../../hal/hal_uart/hal_uart.h" /* Required to call HAL_UART_ISR_Handler() */
#include "../../drivers/Encoder/encoder.h" /* Required to call Encoder_ISR_Handler() */
/**
 * @brief Global Interrupt Service Routine (ISR)
 */
void __interrupt() ISR(void) {
    
    /* 1. Handle Timer0 Overflow Interrupt */
    HAL_Timer0_ISR_Handler();
    
    /* 2. Handle ADC Conversion Complete Interrupt*/
    HAL_ADC_ISR_Handler();
    
    /* 3. Handle UART Interrupt*/
    HAL_UART_ISR_Handler();

    /* 4. Handle Encoder Interrupt*/
    Encoder_ISR_Handler();
}