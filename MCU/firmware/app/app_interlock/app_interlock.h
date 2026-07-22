#ifndef APP_INTERLOCK_H
#define APP_INTERLOCK_H

#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
 * PUBLIC FUNCTION PROTOTYPES
 *
==============================================================================
*/

/**
 * @brief  Khởi tạo module điều khiển khóa chéo 3 LED.
 * @note   Đảm bảo các chân GPIO đã được cấu hình hướng (Input/Output) trong sys_config.
 */
void APP_Interlock_Init(void);

/**
 * @brief  Hàm xử lý logic khóa chéo (State Machine).
 * @note   Hàm này cần được gọi liên tục bên trong vòng lặp vô tận while(1) của main().
 */
void APP_Interlock_Process(void);

#endif /* APP_INTERLOCK_H */