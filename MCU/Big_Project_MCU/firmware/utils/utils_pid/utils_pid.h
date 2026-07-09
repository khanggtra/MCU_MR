#ifndef UTILS_PID_H
#define UTILS_PID_H
#include <stdint.h>

#define Q_factor 1024 // Scaling factor for fixed-point representation of PID coefficients
#define SHIFT_AMOUNT 10 // Number of bits to shift for fixed-point calculations (log2(Q_factor))

typedef struct {
    uint32_t Kp;
    uint32_t Ki;
    uint32_t Kd;

    uint8_t Ts;

    int32_t e_k_1; //e(k-1)
    int32_t e_k_2; //e(k-2)

    int32_t u_k_1; //u(k-1)
    
    int32_t out_min;
    int32_t out_max;
} PID_Controller;

/**
 * @brief  Initializes the PID controller with the specified parameters (*Q_factor scaling applied).
 * @param  pid Pointer to the PID controller structure.
 * @param  p Proportional gain.
 * @param  i Integral gain.
 * @param  d Derivative gain.
 * @param  ts Sampling time.
 * @param  min Minimum output limit.
 * @param  max Maximum output limit.
 */
void PID_Init(PID_Controller *pid, uint32_t p, uint32_t i, uint32_t d, uint8_t ts, int32_t min, int32_t max);

int32_t PID_Compute(PID_Controller *pid, int32_t setpoint, int32_t feedback);

#endif /*UTILS_PID_H*/