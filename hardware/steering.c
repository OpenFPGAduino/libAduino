/*
 * steering.c
 *
 *  Created on: July 17, 2016
 *      Author: Zhizhou Li
 */
#include "brush_motor.h"
#include "FPGA.h"
#define STEERING_CTRL_ADDRESS steering_address
#define STEERING_ID            *((volatile int*) STEERING_CTRL_ADDRESS)
#define STEERING_PWM_ANGLE *((volatile int*) STEERING_CTRL_ADDRESS+1)

void steering_set_angle(void* steering_address, int angle)
{
    STEERING_PWM_ANGLE = (1024.0 * angle / 360);
}



