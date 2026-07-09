#include "app_commute.h"
#include "../../hal/hal_uart/hal_uart.h"
#include "../../utils/utils_string/utils_string.h"
#include <string.h>
#include <stdlib.h>

#define CMD_BUFFER_SIZE 32

void APP_Commute(PID_Controller* pid, int32_t motor_angle, int32_t* setpoint, uint8_t *Run_mode, uint8_t *Calib_done) {
    /* Format: "MOTOR:xxxx\r\n" */
    char buffer[5]; /* 4 digits + null terminator */
    HAL_UART_WriteString(" MOTOR: ");
    Utils_IntToStr_Padded(motor_angle, buffer, 4);
    HAL_UART_WriteString(buffer);
    HAL_UART_WriteString("\r\n");

    static char cmd_buffer[CMD_BUFFER_SIZE];
    static uint8_t cmd_idx = 0; /* Index for storing incoming command characters */
    while (HAL_UART_HasData()) {
        uint8_t c = HAL_UART_ReadChar();

        /* If Line Feed is received, the command is complete */
        if (c == '\n') {
            cmd_buffer[cmd_idx] = '\0'; /* Null-terminate the command string */
            
            char *ptr; /* Shared pointer for substring search */

            /* 1. Check for Setpoint command (SP:) */
            if ((ptr = strstr(cmd_buffer, "SP:")) != NULL) {
                *setpoint = (int16_t)atoi(ptr + 3); /* Skip 3 characters: 'S', 'P', ':' */
            }
            /* 2. Check for Proportional gain command (P:) */
            else if ((ptr = strstr(cmd_buffer, "P:")) != NULL) {
                pid->Kp = (int16_t)atoi(ptr + 2);       /* Skip 2 characters: 'P', ':' */
            }
            /* 3. Check for Integral gain command (I:) */
            else if ((ptr = strstr(cmd_buffer, "I:")) != NULL) {
                pid->Ki = (int16_t)atoi(ptr + 2);       /* Skip 2 characters: 'I', ':' */
            }
            /* 4. Check for Derivative gain command (D:) */
            else if ((ptr = strstr(cmd_buffer, "D:")) != NULL) {
                pid->Kd = (int16_t)atoi(ptr + 2);       /* Skip 2 characters: 'D', ':' */
            }
            else if ((ptr = strstr(cmd_buffer, "RUN:")) != NULL) {
                *Run_mode = (uint8_t)atoi(ptr + 4);      
            }
            else if ((ptr = strstr(cmd_buffer, "CAL:")) != NULL) {
                *Calib_done = (uint8_t)atoi(ptr + 4);      
            }

            cmd_idx = 0; /* Reset the buffer index for the next command */
        } 
        /* Store valid characters, ignore Carriage Return (\r), prevent overflow */
        else if (c != '\r' && cmd_idx < (CMD_BUFFER_SIZE - 1)) {
            cmd_buffer[cmd_idx++] = (char)c;
        }
    }
}