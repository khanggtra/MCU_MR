#ifndef APP_COMMUTE_H
#define APP_COMMUTE_H
#include "../../utils/utils_pid/utils_pid.h"
#include <stdint.h>

void APP_Commute(PID_Controller* pid, int32_t motor_angle, int32_t* setpoint, uint8_t *Run_mode, uint8_t *Calib_done);

#endif /* APP_COMMUTE_H */