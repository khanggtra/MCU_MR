/**
 * @file    sys_config.c
 * @author  Tran Gia Khang
 * @date    April 11, 2026
 * @brief   System Configuration and Board Initialization.
 * @details This module acts as the Board Support Package (BSP). 
 * It initializes all hardware peripherals using discrete modular functions 
 * to ensure high readability and maintainability.
 * @version 1.2
 */

#include "sys_config.h"
#include <xc.h> /* Required for global interrupt (INTCON) manipulation */

/* --- System Services --- */
#include "../sys_tick/sys_tick.h"

/* --- Hardware Abstraction Layer (HAL) --- */
#include "../../hal/hal_uart/hal_uart.h"
/* --- */


/* ==============================================================================
 * PRIVATE FUNCTION PROTOTYPES (Encapsulation)
 * ============================================================================== */
static void System_GPIO_Config(void);
static void System_Services_Config(void);
static void System_Analog_Config(void);
static void System_Communication_Config(void);
static void System_Display_Config(void);
/* ==============================================================================
 * PUBLIC FUNCTION IMPLEMENTATIONS
 * ============================================================================== */

/**
 * @brief  Initializes the entire system hardware and middleware.
 * @note   This function strictly controls the initialization sequence 
 * and interrupt safety.
 */
void sys_config(void) {
    /* 1. CRITICAL SECTION: DISABLE INTERRUPTS */
    INTCONbits.GIE = 0;  
    INTCONbits.PEIE = 0; 

    /* 2. HARDWARE AND MIDDLEWARE INITIALIZATION SEQUENCE */
    System_GPIO_Config();
    System_Services_Config();
    System_Analog_Config();
    System_Display_Config();
    System_Communication_Config();

    /* 3. END OF CRITICAL SECTION: ENABLE INTERRUPTS */
    INTCONbits.PEIE = 1; 
    INTCONbits.GIE = 1;  
}

/* ==============================================================================
 * PRIVATE FUNCTION IMPLEMENTATIONS
 * ============================================================================== */

/**
 * @brief Configures basic I/O pins and their default safety states.
 */
static void System_GPIO_Config(void) {

    
    /* You can add specific pin initializations here later */
    /* e.g., HAL_GPIO_SetDirection(PORT_D, PIN_0, GPIO_DIR_OUTPUT); */
}

/**
 * @brief Initializes system timing services (Heartbeat).
 */
static void System_Services_Config(void) {
    SysTick_Init();
}

/**
 * @brief Configures the Analog-to-Digital Converter and related analog modules.
 */
static void System_Analog_Config(void) {
    // HAL_ADC_Init(ADC_CLK_FOSC_32, ADC_VREF_INTERNAL);
}

/**
 * @brief Initializes serial communication interfaces like UART, SPI, or I2C.
 */
static void System_Communication_Config(void) {
    HAL_UART_Init(9600); /* Initialize UART at 115200 baud rate */
    // HAL_I2C_Init(1000000); /* Initialize I2C at 1Mbps */
}

static void System_Display_Config(void){
    
}