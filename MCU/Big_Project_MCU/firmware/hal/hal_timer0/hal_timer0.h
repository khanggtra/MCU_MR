/**
 * @file    hal_timer0.h
 * @author  Tran Gia Khang
 * @brief   Hardware Abstraction Layer for Timer0 on PIC16F887.
 * @details Configured to generate exactly 1ms interrupts at 20MHz system clock.
 * @version 1.0
 */

#ifndef HAL_TIMER0_H
#define HAL_TIMER0_H

#include <stdbool.h>
#include <xc.h>
#include "../../sys/sys_tick/sys_tick.h"

/**
 * @brief Timer0 Preload value for 1ms tick at 8MHz.
 * Calculation: (256 - 6) * 8 (prescaler) * 0.5us = 250 * 4us = 1000us = 1ms.
 */
#define TMR0_PRELOAD_VALUE 6

/* ==============================================================================
 * API FUNCTION PROTOTYPES
 * ============================================================================== */

void HAL_Timer0_Init(void);


/**
 * @brief  Timer0 Interrupt Service Routine Handler.
 * @note   Must be called inside the global __interrupt() function.
 */
static inline void HAL_Timer0_ISR_Handler(void) {
    if (INTCONbits.T0IF == 1) {
        
        /* 1. Reload the timer for the next 1ms cycle */
        TMR0 = TMR0_PRELOAD_VALUE;
        
        /* 2. Notify the System Tick module to increment its counter */
        SysTick_Increment(); /* Called exactly once every 1ms */
        
        /* 3. Clear hardware interrupt flag */
        INTCONbits.T0IF = 0;
    }
}

#endif /* HAL_TIMER0_H */