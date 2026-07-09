#include "utils_string.h"

uint8_t Utils_UIntToStr_Padded(uint32_t num, char *buffer, uint8_t digits) {
    /* Null-terminate the string first */
    buffer[digits] = '\0';
    
    /* Extract digits from right to left using Modulo operation */
    for (int8_t i = digits - 1; i >= 0; i--) {
        buffer[i] = (char)((num % 10) + '0'); /* Convert to ASCII */
        num /= 10;
    }
    return digits;
}