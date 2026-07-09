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

#endif /* SYS_TICK_H */