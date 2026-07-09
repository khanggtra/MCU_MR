/**
 * @file    hal_timer0.c
 * @author  Tran Gia Khang
 * @brief   HAL implementation for Timer0.
 */

#include "hal_timer0.h"

/* Dependency injection from the System layer */
extern void SysTick_Increment(void);



void HAL_Timer0_Init(void) {
    /* 1. Timer0 Clock Source Select: Internal instruction cycle clock (FOSC/4) */
    OPTION_REGbits.T0CS = 0;
    
    /* 2. Prescaler Assignment: Assign to Timer0 */
    OPTION_REGbits.PSA = 0;
    
    /* 3. Prescaler Rate Select: 1:4 (Bits PS2:PS0 = 001) */
    OPTION_REGbits.PS = 0b001;
    
    /* 4. Preload Timer0 register */
    TMR0 = TMR0_PRELOAD_VALUE;
    
    /* 5. Enable Timer0 Interrupt */
    INTCONbits.T0IF = 0; /* Clear interrupt flag */
    INTCONbits.T0IE = 1; /* Enable Timer0 interrupt */
}

