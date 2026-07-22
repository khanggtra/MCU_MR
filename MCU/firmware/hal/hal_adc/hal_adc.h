#ifndef HAL_ADC_H
#define HAL_ADC_H

#include <stdint.h>

/**
 * @brief Khởi tạo module ADC cho kênh AN12 (Chân RB0)
 */
void HAL_ADC_Init(void);

/**
 * @brief Đọc giá trị ADC 10-bit từ một kênh bất kỳ
 * @param channel Kênh ADC cần đọc (ví dụ: 12 cho RB0/AN12)
 * @return Giá trị ADC thô từ 0 đến 1023
 */
uint16_t HAL_ADC_Read(uint8_t channel);

#endif /* HAL_ADC_H */