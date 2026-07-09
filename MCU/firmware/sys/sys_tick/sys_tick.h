#ifndef SYS_TICK_H
#define SYS_TICK_H

#include <stdint.h>

/* ==============================================================================
 * PUBLIC FUNCTION PROTOTYPES
 * ============================================================================== */

/**
 * @brief  Initializes the System Tick mechanism.
 * @details Configures the underlying hardware timer (e.g., Timer0) to generate 
 * an interrupt precisely every 1 millisecond. This function must be called 
 * during the system boot sequence before any timing functions are used.
 * @param  None
 * @return None
 */
void SysTick_Init(void);

/**
 * @brief  Increments the internal 32-bit system tick counter.
 * @details WARNING: This function must ONLY be called from within the hardware 
 * timer's Interrupt Service Routine (ISR) exactly once every 1ms. 
 * Never call this function from the main application loop.
 * @param  None
 * @return None
 */
void SysTick_Increment(void);

/**
 * @brief  Retrieves the current system uptime.
 * @details Safely reads the global tick variable (handling 8-bit architecture 
 * atomic read protections if necessary). This is the core function used to 
 * build non-blocking task schedulers (State Machines) in the main loop.
 * @param  None
 * @return uint32_t The total number of milliseconds elapsed since system reset.
 */
uint32_t SysTick_GetMs(void);

/**
 * @brief  Executes a safe blocking delay based on system ticks.
 * @details Unlike standard hardware delays (e.g., __delay_ms), this function 
 * polls the tick counter. This allows global interrupts (like UART receive 
 * or ADC conversions) to continue functioning normally in the background 
 * while the CPU waits.
 * @param  delay_ms The required delay time in milliseconds.
 * @return None
 */
void SysTick_DelayMs(uint32_t delay_ms);

#endif /* SYS_TICK_H */