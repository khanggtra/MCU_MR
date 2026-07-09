/**
 * @file    hal_gpio.h
 * @author  Tran Gia Khang
 * @brief   Hardware Abstraction Layer (HAL) for GPIO on PIC16F887.
 * @details This file provides a standardized, hardware-independent interface 
 * to interact with the General Purpose Input/Output (GPIO) pins. 
 * It isolates the hardware-specific registers (TRIS, PORT, ANSEL) 
 * from the higher-level application and driver layers.
 * @version 1.0
 */

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdbool.h>

/**
 * @brief Enumeration for GPIO Ports available on the PIC16F887.
 */
typedef enum {
    PORT_A = 0,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E
} gpio_port_t;

/**
 * @brief Enumeration for individual GPIO Pins.
 */
typedef enum {
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} gpio_pin_t;

/**
 * @brief Enumeration for GPIO Data Direction.
 * @note  In PIC microcontrollers, setting the TRIS bit to 1 configures 
 * the pin as an Input, and 0 configures it as an Output.
 */
typedef enum {
    GPIO_DIR_OUTPUT = 0, /*!< Configures pin as an Output (TRIS = 0) */
    GPIO_DIR_INPUT  = 1  /*!< Configures pin as an Input (TRIS = 1) */
} gpio_dir_t;

/**
 * @brief Enumeration for GPIO Logic States.
 */
typedef enum {
    GPIO_LOW  = 0,       /*!< Logic Low (0V) */
    GPIO_HIGH = 1        /*!< Logic High (VDD) */
} gpio_state_t;


/* ==============================================================================
 * API FUNCTION PROTOTYPES
 * ============================================================================== */


/**
 * @brief  Configures the data direction (Input or Output) of a specific pin.
 * @param  port The target GPIO port (e.g., PORT_B).
 * @param  pin  The target GPIO pin (e.g., PIN_3).
 * @param  dir  The desired direction (GPIO_DIR_INPUT or GPIO_DIR_OUTPUT).
 */
void HAL_GPIO_SetDirection(gpio_port_t port, gpio_pin_t pin, gpio_dir_t dir);

void HAL_GPIO_PullUpEnable(gpio_pin_t pin);

/**
 * @brief  Writes a logic state to a specific output pin.
 * @param  port  The target GPIO port.
 * @param  pin   The target GPIO pin.
 * @param  state The logic state to write (GPIO_HIGH or GPIO_LOW).
 * @note   The pin must be configured as an output prior to calling this function.
 */
void HAL_GPIO_WritePin(gpio_port_t port, gpio_pin_t pin, gpio_state_t state);

/**
 * @brief  Reads the current logic state of a specific input pin.
 * @param  port The target GPIO port.
 * @param  pin  The target GPIO pin.
 * @return The current logic state (GPIO_HIGH or GPIO_LOW).
 */
gpio_state_t HAL_GPIO_ReadPin(gpio_port_t port, gpio_pin_t pin);

/**
 * @brief  Toggles (inverts) the current logic state of a specific output pin.
 * @param  port The target GPIO port.
 * @param  pin  The target GPIO pin.
 * @note   If the pin is currently HIGH, it will become LOW, and vice versa.
 */
void HAL_GPIO_TogglePin(gpio_port_t port, gpio_pin_t pin);

#endif /* HAL_GPIO_H */