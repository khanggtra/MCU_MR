#include <xc.h>
#include "../../hal/hal_timer0/hal_timer0.h" /* Required to call HAL_Timer0_ISR_Handler() */
#include "../../hal/hal_uart/hal_uart.h" /* Required to call HAL_UART_ISR_Handler() */
/**
 * @brief Global Interrupt Service Routine (ISR)
 */
void __interrupt() ISR(void) {
    
    /* 1. Handle Timer0 Overflow Interrupt */
    HAL_Timer0_ISR_Handler();
    
    /* 2. Handle UART Interrupt*/
    HAL_UART_ISR_Handler();
}