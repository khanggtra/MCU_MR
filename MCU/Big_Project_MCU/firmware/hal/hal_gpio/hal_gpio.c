/**
 * @file    hal_gpio.c
 * @author  Tran Gia Khang
 * @brief   Hardware Abstraction Layer implementation for GPIO on PIC16F887.
 * @details This file implements the functions declared in hal_gpio.h. 
 * It contains the actual register-level manipulation (TRIS, PORT, ANSEL) 
 * specific to the Microchip PIC16F887 microcontroller.
 * @version 1.0
 */

#include "hal_gpio.h"
#include <xc.h> /* Microchip XC8 compiler specific header for device registers */
/* ==============================================================================
 * API FUNCTION IMPLEMENTATIONS
 * ============================================================================== */

/**
 * @brief Configures the data direction of a specific pin and automatically
 *        disables its analog feature to ensure it works as a Digital I/O.
 */
void HAL_GPIO_SetDirection(gpio_port_t port, gpio_pin_t pin, gpio_dir_t dir) {
    switch (port) {
        case PORT_A: 
            /* Turn off Analog for PORTA (AN0-AN4) */
            if (pin >= 0 && pin <= 3) {
                ANSEL &= ~(1 << pin);       /* RA0->AN0, RA1->AN1, RA2->AN2, RA3->AN3 */
            } else if (pin == 5) {
                ANSEL &= ~(1 << 4);         /* RA5->AN4 */
            }
            
            /* Configure data direction (TRIS) */
            if (dir == GPIO_DIR_INPUT) {
                TRISA |= (1 << pin);        /* Set bit to 1 (Input) */
            } else {
                TRISA &= ~(1 << pin);       /* Clear bit to 0 (Output) */
            }
            break;
            
        case PORT_B: 
            /* Turn off Analog for PORTB (AN8-AN13) */
            if      (pin == 0) ANSELH &= ~(1 << 4); /* RB0 -> AN12 */
            else if (pin == 1) ANSELH &= ~(1 << 2); /* RB1 -> AN10 */
            else if (pin == 2) ANSELH &= ~(1 << 0); /* RB2 -> AN8  */
            else if (pin == 3) ANSELH &= ~(1 << 1); /* RB3 -> AN9  */
            else if (pin == 4) ANSELH &= ~(1 << 3); /* RB4 -> AN11 */
            else if (pin == 5) ANSELH &= ~(1 << 5); /* RB5 -> AN13 */
            
            if (dir == GPIO_DIR_INPUT) {
                TRISB |= (1 << pin);
            } else {
                TRISB &= ~(1 << pin);
            }
            break;
            
        case PORT_C: 
            /* PORTC không có chân Analog trên PIC16F887 */
            if (dir == GPIO_DIR_INPUT) {
                TRISC |= (1 << pin);
            } else {
                TRISC &= ~(1 << pin);
            }
            break;
            
        case PORT_D: 
            /* PORTD không có chân Analog trên PIC16F887 */
            if (dir == GPIO_DIR_INPUT) {
                TRISD |= (1 << pin);
            } else {
                TRISD &= ~(1 << pin);
            }
            break;
            
        case PORT_E: 
            /* Xử lý Analog cho PORTE (AN5-AN7) */
            if (pin >= 0 && pin <= 2) {
                ANSEL &= ~(1 << (pin + 5)); /* RE0->AN5, RE1->AN6, RE2->AN7 */
            }
            
            if (dir == GPIO_DIR_INPUT) {
                TRISE |= (1 << pin);
            } else {
                TRISE &= ~(1 << pin);
            }
            break;
            
        default: 
            /* Invalid port, do nothing */
            break;
    }
}

void HAL_GPIO_PullUpEnable(gpio_pin_t pin) {
    WPUB |= (1 << pin); /* Enable weak pull-up on PORTB pins */
}

/**
 * @brief Writes a logic state to a specific output pin.
 */
void HAL_GPIO_WritePin(gpio_port_t port, gpio_pin_t pin, gpio_state_t state) {
    switch (port) {
        case PORT_A:
            if (state == GPIO_HIGH) {
                PORTA |= (1 << pin);        /* Set pin HIGH */
            } else {
                PORTA &= ~(1 << pin);       /* Set pin LOW */
            }
            break;
            
        case PORT_B:
            if (state == GPIO_HIGH) {
                PORTB |= (1 << pin);
            } else {
                PORTB &= ~(1 << pin);
            }
            break;
            
        case PORT_C:
            if (state == GPIO_HIGH) {
                PORTC |= (1 << pin);
            } else {
                PORTC &= ~(1 << pin);
            }
            break;
            
        case PORT_D:
            if (state == GPIO_HIGH) {
                PORTD |= (1 << pin);
            } else {
                PORTD &= ~(1 << pin);
            }
            break;
            
        case PORT_E:
            if (state == GPIO_HIGH) {
                PORTE |= (1 << pin);
            } else {
                PORTE &= ~(1 << pin);
            }
            break;
            
        default: 
            break;
    }
}

/**
 * @brief Reads the current logic state of a specific input pin.
 */
gpio_state_t HAL_GPIO_ReadPin(gpio_port_t port, gpio_pin_t pin) {
    bool bit_status = false;
    
    switch (port) {
        case PORT_A: 
            bit_status = (PORTA & (1 << pin)) ? true : false; 
            break;
        case PORT_B: 
            bit_status = (PORTB & (1 << pin)) ? true : false; 
            break;
        case PORT_C: 
            bit_status = (PORTC & (1 << pin)) ? true : false; 
            break;
        case PORT_D: 
            bit_status = (PORTD & (1 << pin)) ? true : false; 
            break;
        case PORT_E: 
            bit_status = (PORTE & (1 << pin)) ? true : false; 
            break;
        default: 
            return GPIO_LOW; /* Return safe default on error */
    }
    
    return bit_status ? GPIO_HIGH : GPIO_LOW;
}

/**
 * @brief Toggles (inverts) the current logic state of a specific output pin.
 */
void HAL_GPIO_TogglePin(gpio_port_t port, gpio_pin_t pin) {
    switch (port) {
        case PORT_A: 
            PORTA ^= (1 << pin); /* XOR operation to toggle the bit */
            break;
        case PORT_B: 
            PORTB ^= (1 << pin); 
            break;
        case PORT_C: 
            PORTC ^= (1 << pin); 
            break;
        case PORT_D: 
            PORTD ^= (1 << pin); 
            break;
        case PORT_E: 
            PORTE ^= (1 << pin); 
            break;
        default: 
            break;
    }
}