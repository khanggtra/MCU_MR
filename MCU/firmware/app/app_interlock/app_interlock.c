#include "app_interlock.h"
#include "../../hal/hal_gpio/hal_gpio.h"

/*
==============================================================================
 * PRIVATE ENUMS & VARIABLES (Encapsulation)
 *
==============================================================================
*/

/**
 * @brief Định nghĩa các trạng thái khóa chéo nội bộ
 */
typedef enum {
    LOCK_NONE = 0, /* Không có nút nào nhấn, hệ thống tự do */
    LOCK_RED,      /* BT1 (RB3) đang khóa -> LED Đỏ (RD4) sáng */
    LOCK_GREEN,    /* BT2 (RB4) đang khóa -> LED Xanh (RD5) sáng */
    LOCK_YELLOW    /* BT3 (RB5) đang khóa -> LED Vàng (RD6) sáng */
} interlock_state_t;

/* Biến lưu trạng thái hiện tại, giấu kín (static) không cho bên ngoài truy cập */
static interlock_state_t g_current_lock = LOCK_NONE;

/*
==============================================================================
 * PUBLIC FUNCTION IMPLEMENTATIONS
 *
==============================================================================
*/

void APP_Interlock_Init(void) {
    /* Đảm bảo trạng thái ban đầu là tự do và tất cả LED đều tắt */
    g_current_lock = LOCK_NONE;
    
    HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW); /* Tắt LED Đỏ */
    HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW); /* Tắt LED Xanh */
    HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW); /* Tắt LED Vàng */
}

void APP_Interlock_Process(void) {
    /* 1. Đọc trạng thái nút nhấn (Active LOW do dùng Pull-up) */
    bool bt1_pressed = (HAL_GPIO_ReadPin(PORT_B, PIN_3) == GPIO_LOW);
    bool bt2_pressed = (HAL_GPIO_ReadPin(PORT_B, PIN_4) == GPIO_LOW);
    bool bt3_pressed = (HAL_GPIO_ReadPin(PORT_B, PIN_5) == GPIO_LOW);

    /* 2. Máy trạng thái xử lý khóa chéo */
    switch (g_current_lock) {
        
        case LOCK_NONE:
            /* Hệ thống tự do: Nút nào nhấn trước sẽ chiếm quyền khóa */
            if (bt1_pressed) {
                g_current_lock = LOCK_RED;
                HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_HIGH); /* Bật LED Đỏ (RD4) */
            } 
            else if (bt2_pressed) {
                g_current_lock = LOCK_GREEN;
                HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_HIGH); /* Bật LED Xanh (RD5) */
            } 
            else if (bt3_pressed) {
                g_current_lock = LOCK_YELLOW;
                HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_HIGH); /* Bật LED Vàng (RD6) */
            }
            break;

        case LOCK_RED:
            /* BT1 (RB3) đang khóa: Chỉ kiểm tra khi nào BT1 được THẢ RA */
            if (!bt1_pressed) {
                HAL_GPIO_WritePin(PORT_D, PIN_4, GPIO_LOW);  /* Tắt LED Đỏ */
                g_current_lock = LOCK_NONE;                  /* Giải phóng khóa */
            }
            /* Lờ đi mọi tác động từ BT2 và BT3 */
            break;

        case LOCK_GREEN:
            /* BT2 (RB4) đang khóa: Chỉ kiểm tra khi nào BT2 được THẢ RA */
            if (!bt2_pressed) {
                HAL_GPIO_WritePin(PORT_D, PIN_5, GPIO_LOW);  /* Tắt LED Xanh */
                g_current_lock = LOCK_NONE;                  /* Giải phóng khóa */
            }
            /* Lờ đi mọi tác động từ BT1 và BT3 */
            break;

        case LOCK_YELLOW:
            /* BT3 (RB5) đang khóa: Chỉ kiểm tra khi nào BT3 được THẢ RA */
            if (!bt3_pressed) {
                HAL_GPIO_WritePin(PORT_D, PIN_6, GPIO_LOW);  /* Tắt LED Vàng */
                g_current_lock = LOCK_NONE;                  /* Giải phóng khóa */
            }
            /* Lờ đi mọi tác động từ BT1 và BT2 */
            break;

        default:
            g_current_lock = LOCK_NONE;
            break;
    }
}