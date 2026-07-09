/**
 * @file    sys_config.h
 * @author  Tran Gia Khang
 * @date    April 11, 2026
 * @brief   System Configuration and Board Initialization header.
 * @details This header defines the public interface for the Board Support 
 * Package (BSP). It provides the core initialization routine required 
 * to start the microcontroller safely.
 * @version 1.1
 */

/* Include Guard: Prevents double inclusion of this header file */
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