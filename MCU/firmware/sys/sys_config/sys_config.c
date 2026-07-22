#include "sys_config.h"
#include <xc.h> /* Required for global interrupt (INTCON) manipulation */

/* --- System Services --- */
#include "../sys_tick/sys_tick.h"

/* --- Hardware Abstraction Layer (HAL) --- */
#include "../../hal/hal_uart/hal_uart.h"
#include "../../hal/hal_gpio/hal_gpio.h"

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
    /* OUTPUT: LED (RD4: Đỏ, RD5: Xanh, RD6: Vàng) */
    HAL_GPIO_SetDirection(PORT_D, PIN_4, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(PORT_D, PIN_5, GPIO_DIR_OUTPUT);
    HAL_GPIO_SetDirection(PORT_D, PIN_6, GPIO_DIR_OUTPUT);

    HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);
    HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW);

    /* INPUT: BUTTON (RB3: BT1, RB4: BT2, RB5: BT3) */
    HAL_GPIO_SetDirection(PORT_B, PIN_3, GPIO_DIR_INPUT);
    HAL_GPIO_PullUpEnable(PIN_3);

    HAL_GPIO_SetDirection(PORT_B, PIN_4, GPIO_DIR_INPUT);
    HAL_GPIO_PullUpEnable(PIN_4);

    HAL_GPIO_SetDirection(PORT_B, PIN_5, GPIO_DIR_INPUT);
    HAL_GPIO_PullUpEnable(PIN_5);
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
    
}

/**
 * @brief Initializes serial communication interfaces like UART, SPI, or I2C.
 */
static void System_Communication_Config(void) {
    HAL_UART_Init(9600); /* Initialize UART at 115200 baud rate */
}

static void System_Display_Config(void){
    
}