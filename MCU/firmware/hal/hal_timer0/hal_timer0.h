#ifndef HAL_TIMER0_H
#define HAL_TIMER0_H

#include <stdbool.h>
#include <xc.h>
#include "../../sys/sys_tick/sys_tick.h"

/**
 * @brief Timer0 Preload value for 1ms tick at 20MHz.
 * Calculation: (256 - 100) * 32 (prescaler) * 0.2us = 250 * 4us = 1000us = 1ms.
 */
#define TMR0_PRELOAD_VALUE 100

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