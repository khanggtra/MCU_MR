/**
 * @file    sys_tick.c
 * @author  Tran Gia Khang
 * @brief   System Tick implementation.
 */

#include "sys_tick.h"
#include "../../hal/hal_timer0/hal_timer0.h"
#include <xc.h> /* Required for GIE manipulation */

/* Global variable to track system uptime in milliseconds.
 * 'volatile' is mandatory because it is modified inside the ISR.
 */
static volatile uint32_t g_system_ticks_ms = 0;

void SysTick_Init(void) {
    /* Initialize the underlying hardware timer */
    HAL_Timer0_Init();
}

void SysTick_Increment(void) {
    /* This function is called every 1ms by HAL_Timer0_ISR_Handler() */
    g_system_ticks_ms++;
}

uint32_t SysTick_GetMs(void) {
    uint32_t current_ticks;
    
    /* CRITICAL SECTION: Disable global interrupts.
     * Reading a 32-bit variable on an 8-bit PIC takes 4 clock cycles.
     * If an interrupt occurs in the middle of this read, the data will be corrupted.
     */
    INTCONbits.GIE = 0;  
    current_ticks = g_system_ticks_ms;
    INTCONbits.GIE = 1;  
    
    return current_ticks;
}

/**
 * @brief Blocking delay based on System Ticks.
 * @note  While this is blocking, it is safer than __delay_ms() because 
 * interrupts (like ADC or UART) continue to function during this delay.
 */
void SysTick_DelayMs(uint32_t delay_ms) {
    uint32_t start_time = SysTick_GetMs();
    
    while ((SysTick_GetMs() - start_time) < delay_ms) {
        /* Wait */
    }
}