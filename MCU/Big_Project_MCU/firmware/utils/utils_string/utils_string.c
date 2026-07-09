/**
 * @file    utils_string.c
 * @author  Tran Gia Khang
 * @brief   Implementation of lightweight string utilities.
 */

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

uint8_t Utils_IntToStr_Padded(int32_t num, char *buffer, uint8_t digits) {
    uint8_t stop_idx = 0;
    uint32_t abs_num;

    /* 1. Handle negative numbers safely */
    if (num < 0) {
        buffer[0] = '-';
        stop_idx = 1; /* Stop extracting numbers before overwriting the '-' sign */
        abs_num = (uint32_t)(-num); 
    } else {
        abs_num = (uint32_t)num;
    }

    /* 2. Extract digits from right to left using Modulo math */
    for (int8_t i = digits - 1; i >= stop_idx; i--) {
        buffer[i] = (char)((abs_num % 10) + '0'); /* Convert to ASCII */
        abs_num /= 10;
    }
    
    for (uint8_t i = stop_idx; i < digits - 1; i++) {
        if (buffer[i] == '0') {
            buffer[i] = ' ';
        } else {
            break;
        }
    }

    /* 3. Terminate the string safely */
    buffer[digits] = '\0';

    return digits; /* Length is constant */
}