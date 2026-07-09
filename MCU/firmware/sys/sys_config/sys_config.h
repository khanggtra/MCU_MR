#ifndef SYS_CONFIG_H
#define SYS_CONFIG_H

/* ==============================================================================
 * PUBLIC FUNCTION PROTOTYPES
 * ============================================================================== */

/**
 * @brief  Initializes the entire system hardware and middleware.
 * @note   This function MUST be the very first routine called inside the main() 
 * function. It automatically handles the safe configuration of GPIO, SysTick, 
 * Analog modules, UART, and the global interrupt enable sequence.
 * @param  None
 * @return None
 */
void sys_config(void);

#endif /* SYS_CONFIG_H */