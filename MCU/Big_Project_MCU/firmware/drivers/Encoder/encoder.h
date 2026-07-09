#ifndef ENCODER_H
#define ENCODER_H
#include "../../hal/hal_gpio/hal_gpio.h"
#include <stdint.h>

void Encoder_Init(gpio_pin_t pinA, gpio_pin_t pinB);
int32_t Encoder_GetAngle(void);
int32_t Encoder_GetTicks(void);
void Encoder_ISR_Handler(void);

void Encoder_Reset(void);
#endif /* ENCODER_H */