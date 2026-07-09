#include "hal_uart.h"
#include "../../project_config/project_config.h"
#include <xc.h>


/* ==============================================================================
 * PRIVATE MACROS & VARIABLES (Encapsulated Ring Buffer)
 * ============================================================================== */

/* Buffer size must be a power of 2 for optimal pointer arithmetic */
#define UART_RX_BUFFER_SIZE 64

static volatile uint8_t rx_buffer[UART_RX_BUFFER_SIZE];
static volatile uint8_t rx_head = 0; /* Hardware Write Pointer */
static volatile uint8_t rx_tail = 0; /* Software Read Pointer */


/* ==============================================================================
 * API FUNCTION IMPLEMENTATIONS
 * ============================================================================== */

void HAL_UART_Init(uint32_t baud_rate) {
    /* 1. Baud Rate Calculation (Asynchronous mode, High Speed BRGH=1) */
    TXSTAbits.BRGH = 1;
    BAUDCTLbits.BRG16 = 1;
    uint16_t spbrg_value = (uint16_t)((_XTAL_FREQ / (4UL * baud_rate)) - 1);
    SPBRG = (uint8_t)(spbrg_value & 0xFF);
    SPBRGH = (uint8_t)(spbrg_value >> 8);

    /* 2. Configure TX/RX Pins */

    TRISCbits.TRISC6 = 1; 
    TRISCbits.TRISC7 = 1; 

    /* 3. Enable Serial Port, Transmit, and Continuous Receive */
    RCSTAbits.SPEN = 1; 
    TXSTAbits.TXEN = 1; 
    RCSTAbits.CREN = 1; 

    /* 4. Enable Receive Interrupts */
    PIR1bits.RCIF = 0;  /* Clear interrupt flag initially */
    PIE1bits.RCIE = 1;  /* Enable UART Receive Interrupt */
}

/* ------------------------------------------------------------------------------
 * RECEIVE FUNCTIONS
 * ------------------------------------------------------------------------------ */

bool HAL_UART_HasData(void) {
    /* Safe read of pointers without disabling interrupts, 
     * as this is a simple atomic comparison. 
     */
    return (rx_head != rx_tail);
}

uint8_t HAL_UART_ReadChar(void) {
    uint8_t data = 0;

    if (rx_head != rx_tail) {
        data = rx_buffer[rx_tail];
        rx_tail = (rx_tail + 1) % UART_RX_BUFFER_SIZE;
    }
    
    return data;
}

/* ------------------------------------------------------------------------------
 * TRANSMIT FUNCTIONS
 * ------------------------------------------------------------------------------ */

void HAL_UART_WriteChar(uint8_t data) {
    /* Wait until the Transmit Buffer (TXREG) is empty.
     * PIR1bits.TXIF goes HIGH when TXREG is empty and ready for new data.
     */
    while (PIR1bits.TXIF == 0) {
        /* Block and wait */
    }
    
    /* Load the data into the hardware transmit register */
    TXREG = data;
}

void HAL_UART_WriteInt(const int32_t value) {
    char buffer[12];
    int index = 0;
    int32_t temp = value;

    /* Handle negative numbers */
    if (temp < 0) {
        buffer[index++] = '-';
        temp = -temp;
    }

    /* Convert integer to string in reverse order */
    char temp_buffer[10];
    int temp_index = 0;

    do {
        temp_buffer[temp_index++] = (temp % 10) + '0';
        temp /= 10;
    } while (temp > 0);

    /* Reverse the digits into the final buffer */
    for (int i = temp_index - 1; i >= 0; i--) {
        buffer[index++] = temp_buffer[i];
    }
    
    buffer[index] = '\0'; /* Null-terminate the string */

    HAL_UART_WriteString(buffer);
}

void HAL_UART_WriteString(const char *str) {
    /* Loop through the string until the null-terminator '\0' is reached */
    while (*str != '\0') {
        HAL_UART_WriteChar((uint8_t)(*str));
        str++; /* Move to the next character in the array */
    }
}

/* ------------------------------------------------------------------------------
 * INTERRUPT SERVICE ROUTINE
 * ------------------------------------------------------------------------------ */

void HAL_UART_ISR_Handler(void) {
    /* Verify the interrupt source is UART Receive */
    if (PIR1bits.RCIF == 1) {
        
        /* Check and clear Overrun Error to prevent hardware lockup */
        if (RCSTAbits.OERR) {
            RCSTAbits.CREN = 0; 
            asm("nop");         
            RCSTAbits.CREN = 1; 
        }

        /* Read data from hardware (This action automatically clears RCIF flag) */
        uint8_t received_byte = RCREG;

        /* Calculate next head position */
        uint8_t next_head = (rx_head + 1) % UART_RX_BUFFER_SIZE;
        
        /* Store data if buffer is not full */
        if (next_head != rx_tail) {
            rx_buffer[rx_head] = received_byte; 
            rx_head = next_head;                
        }
    }
}