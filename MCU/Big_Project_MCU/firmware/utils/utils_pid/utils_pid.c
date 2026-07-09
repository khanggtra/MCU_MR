#include "utils_pid.h"
#include <stdint.h>

void PID_Init(PID_Controller *pid, uint32_t p, uint32_t i, uint32_t d, uint8_t ts, int32_t min, int32_t max){
    pid->Kp = p;
    pid->Ki = i;
    pid->Kd = d;
    pid->Ts = ts;

    pid->e_k_1 = 0;
    pid->e_k_2 = 0;
    pid->u_k_1 = 0;
    pid->Ts = ts;

    pid->out_max = max;
    pid->out_min = min;
}

int32_t PID_Compute(PID_Controller *pid, int32_t setpoint, int32_t feedback){
    int32_t e = (setpoint - feedback)*Q_factor;

    int32_t alpha = pid->Kp + ((pid->Ki)*(pid->Ts)) + (pid->Kd);
    int32_t beta = - (pid->Kp + 2*(pid->Kd));
    int32_t gamma = pid->Kd;

    int32_t delta_u = ((alpha*e)>>SHIFT_AMOUNT) + ((beta*(pid->e_k_1))>>SHIFT_AMOUNT) + ((gamma*(pid->e_k_2))>>SHIFT_AMOUNT);

    int32_t u_k = pid->u_k_1 + delta_u;

    if(u_k<pid->out_min) u_k = pid->out_min;
    if(u_k>pid->out_max) u_k = pid->out_max;

    pid->e_k_2 = pid->e_k_1;
    pid->e_k_1 = e;
    pid->u_k_1 = u_k;

    return u_k;

}