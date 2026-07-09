#include "encoder.h"
#include "../../hal/hal_gpio/hal_gpio.h"
#include <xc.h>

#define PPR 495 /* Pulses per Revolution for the encoder */
static uint8_t enc_pin_a = 0;
static uint8_t enc_pin_b = 0;
static uint8_t enc_mask  = 0;

static volatile int32_t encoder_ticks = 0;
static uint8_t portb_old = 0;



void Encoder_Init(gpio_pin_t pinA, gpio_pin_t pinB) {
    /* Initialize GPIO pins for encoder input */
    HAL_GPIO_SetDirection(PORT_B, pinA, GPIO_DIR_INPUT);
    HAL_GPIO_SetDirection(PORT_B, pinB, GPIO_DIR_INPUT);
    enc_pin_a = (uint8_t)pinA;
    enc_pin_b = (uint8_t)pinB;
    enc_mask = (1 << enc_pin_a) | (1 << enc_pin_b);
    TRISB |= enc_mask; /* Set encoder pins as input */
    OPTION_REGbits.nRBPU = 0; /* Enable PORTB pull-ups */
    WPUB |= enc_mask;   /* Enable pull-ups on encoder pins */
    IOCB |= enc_mask; /* Enable interrupt-on-change for encoder pins */

    portb_old = PORTB; /* Initialize old state for change detection */
    INTCONbits.RBIF = 0; /* Clear interrupt flag */
    INTCONbits.RBIE = 1; /* Enable PORTB change interrupt */
}  

int32_t Encoder_GetAngle(void) {
    static int32_t angle = 0; 
    
    /* GỌI HÀM AN TOÀN thay vì đọc trực tiếp biến encoder_ticks */
    int32_t safe_ticks = Encoder_GetTicks(); 
    
    angle = (safe_ticks * 360) / PPR; /* Convert ticks to angle */
    return angle;
}

void Encoder_ISR_Handler(void) {
    if (INTCONbits.RBIF) {
        uint8_t portb_new = PORTB; 
        uint8_t changed = portb_new ^ portb_old; 

        if (changed & enc_mask) { 
            
            /* Dịch bit động dựa trên biến cấu hình đã lưu */
            uint8_t old_A = (portb_old >> enc_pin_a) & 1;
            uint8_t old_B = (portb_old >> enc_pin_b) & 1;
            uint8_t new_A = (portb_new >> enc_pin_a) & 1;
            uint8_t new_B = (portb_new >> enc_pin_b) & 1;

            int8_t dir = (old_A ^ new_B) - (new_A ^ old_B);
            encoder_ticks += dir;
        }

        portb_old = portb_new; 
        INTCONbits.RBIF = 0;   
    }
}

int32_t Encoder_GetTicks(void) {
    int32_t ticks;
    
    bool gie_state = INTCONbits.GIE; 
    INTCONbits.GIE = 0;              
    
    ticks = encoder_ticks;           
    
    INTCONbits.GIE = gie_state;      
    return ticks;
}

void Encoder_Reset(void) {
    bool gie_state = INTCONbits.GIE; 
    INTCONbits.GIE = 0; 
    
    encoder_ticks = 0;
    
    INTCONbits.GIE = gie_state; 
}