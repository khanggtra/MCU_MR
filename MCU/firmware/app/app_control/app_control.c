#include <xc.h>
#include "../../hal/hal_timer0/hal_timer0.h" 
#include "../../hal/hal_uart/hal_uart.h" 

/* Các biến toàn cục dùng chung cho ngắt và Main (volatile là bắt buộc) */
volatile uint8_t lock_state = 0;     /* 0: Rảnh, 1: LED1(RD7), 2: LED2(RD5), 3: LED3(RD6) */
volatile uint32_t timer_start = 0;   /* Mốc thời gian bắt đầu đếm 5s */
volatile bool pot_enabled = false;   /* Trạng thái cho phép biến trở can thiệp */

/* Hàm nguyên mẫu để gọi Hardware PWM */
extern void HardwarePWM_Steer(uint8_t led_id);
extern void HardwarePWM_SetDuty(uint16_t duty);

void __interrupt() ISR(void) {
    /* 1. Xử lý Ngắt Timer0 (SysTick) */
    HAL_Timer0_ISR_Handler();
    
    /* 2. Xử lý Ngắt UART */
    HAL_UART_ISR_Handler();

    /* 3. Xử lý Ngắt Nút Nhấn (Interrupt-On-Change PORTB) */
    if (INTCONbits.RBIF == 1) {
        uint8_t curr_portb = PORTB; /* Đọc PORTB để xóa trạng thái chốt (mismatch) */
        static uint8_t prev_portb = 0xFF; /* Trạng thái trước đó, mặc định HIGH do có Pull-up */
        
        /* Tìm ra nút nào vừa được nhấn (chuyển từ HIGH xuống LOW -> Falling Edge) */
        uint8_t falling_edges = (prev_portb ^ curr_portb) & prev_portb;

        /* Nút RB2: Bật/Tắt chức năng biến trở (Chỉ tác dụng khi đang có LED đếm 5s) */
        if (falling_edges & (1 << 2)) {
            if (lock_state != 0) {
                pot_enabled = !pot_enabled; 
            }
        }
        
        /* Nút RB3: Can thiệp LED 1 (RD7) */
        if (falling_edges & (1 << 3)) {
            if (lock_state == 0 || lock_state == 1) { 
                lock_state = 1;
                timer_start = SysTick_GetMs(); /* (Re)start 5s */
                pot_enabled = false;           /* Mặc định tắt biến trở khi vừa nhấn */
                HardwarePWM_Steer(1);          /* Hướng PWM ra RD7 */
                HardwarePWM_SetDuty(1023);     /* Sáng hết cỡ (hằng số) */
            }
        }
        
        /* Nút RB4: Can thiệp LED 2 (RD5) */
        if (falling_edges & (1 << 4)) {
            if (lock_state == 0 || lock_state == 2) {
                lock_state = 2;
                timer_start = SysTick_GetMs();
                pot_enabled = false;
                HardwarePWM_Steer(2);          /* Hướng PWM ra RD5 */
                HardwarePWM_SetDuty(1023);
            }
        }
        
        /* Nút RB5: Can thiệp LED 3 (RD6) */
        if (falling_edges & (1 << 5)) {
            if (lock_state == 0 || lock_state == 3) {
                lock_state = 3;
                timer_start = SysTick_GetMs();
                pot_enabled = false;
                HardwarePWM_Steer(3);          /* Hướng PWM ra RD6 */
                HardwarePWM_SetDuty(1023);
            }
        }

        prev_portb = curr_portb; /* Cập nhật trạng thái cũ */
        INTCONbits.RBIF = 0;     /* Xóa cờ ngắt */
    }
}