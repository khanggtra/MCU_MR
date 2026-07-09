#ifndef HAL_UART_H
#define HAL_UART_H

#include <stdint.h>
#include <stdbool.h>

/* ==============================================================================
 * PUBLIC FUNCTION PROTOTYPES
 * ============================================================================== */

/**
 * @brief  Initializes the UART module with the specified baud rate.
 * @param  baud_rate Desired baud rate (e.g., 9600, 115200).
 */
void HAL_UART_Init(uint32_t baud_rate);

/* --- UART RECEIVE (NON-BLOCKING) --- */

/**
 * @brief  Checks if there is unread data in the UART Ring Buffer.
 * @return true if data is available, false if the buffer is empty.
 */
bool HAL_UART_HasData(void);

/**
 * @brief  Reads one byte from the Ring Buffer.
 * @note   Always verify HAL_UART_HasData() == true before calling.
 * @return The oldest unread byte in the buffer.
 */
uint8_t HAL_UART_ReadChar(void);


/* --- UART TRANSMIT (BLOCKING) --- */

/**
 * @brief  Transmits a single byte via UART.
 * @details Blocks execution until the hardware transmit buffer is empty,
 * then loads the new byte.
 * @param  data The 8-bit character to send.
 */
void HAL_UART_WriteChar(uint8_t data);

/**
 * @brief  Transmits a null-terminated string via UART.
 * @param  str Pointer to the character array (string) to be sent.
 */

 void HAL_UART_WriteInt(const int32_t value);

void HAL_UART_WriteString(const char *str);


/* --- INTERRUPT HANDLER --- */

/**
 * @brief  UART Receive Interrupt Service Routine Handler.
 * @note   Must be placed inside the global __interrupt() function.
 */
void HAL_UART_ISR_Handler(void);

#endif /* HAL_UART_H */