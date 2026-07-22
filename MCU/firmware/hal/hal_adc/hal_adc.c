#include "hal_adc.h"
#include <xc.h>

#define _XTAL_FREQ 20000000UL

void HAL_ADC_Init(void) {

    TRISBbits.TRISB0 = 1;
    ANSELHbits.ANS12 = 1; 

    ADCON1bits.ADFM = 1;
    ADCON1bits.VCFG1 = 0;
    ADCON1bits.VCFG0 = 0;

    ADCON0bits.ADCS1 = 1;
    ADCON0bits.ADCS0 = 0;
    
    /* Bật module ADC */
    ADCON0bits.ADON = 1;
}

uint16_t HAL_ADC_Read(uint8_t channel) {
    ADCON0 &= 0xC3;
    ADCON0 |= (uint8_t)((channel & 0x0F) << 2);

    /* Thời gian nạp tụ Sample & Hold (Acquisition time ~ 20us) */
    __delay_us(20);

    ADCON0bits.GO_nDONE = 1;

    while (ADCON0bits.GO_nDONE == 1) {
    }

    /* Ghép kết quả 10-bit từ 2 thanh ghi ADRESH và ADRESL */
    return (uint16_t)((ADRESH << 8) | ADRESL);
}