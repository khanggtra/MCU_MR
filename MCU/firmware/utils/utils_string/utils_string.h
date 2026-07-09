#ifndef UTILS_STRING_H
#define UTILS_STRING_H

#include <stdint.h>
#include <stdbool.h>

/* ==============================================================================
 * PUBLIC FUNCTION PROTOTYPES
 * ============================================================================== */

/**
 * @brief  Converts an unsigned integer to a zero-padded string.
 * @param  num    The number to convert (e.g., 45).
 * @param  buffer Pointer to the character array to store the result.
 * @param  digits Number of digits to pad with zeros (e.g., 4 -> "0045").
 */
uint8_t Utils_UIntToStr_Padded(uint32_t num, char *buffer, uint8_t digits);

/**
 * @brief  Converts a signed integer to a fixed-width zero-padded string.
 * @details Handles negative numbers by fixing the '-' sign at the first index.
 * Example (digits = 4): 45 -> "0045", -12 -> "-012".
 * @param  num    The signed number to convert.
 * @param  buffer Pointer to the character array to store the result.
 * @param  digits Total length of the numeric string (excluding null-terminator).
 * @return The length of the generated string (always equals 'digits').
 */
uint8_t Utils_IntToStr_Padded(int32_t num, char *buffer, uint8_t digits);

#endif /* UTILS_STRING_H */