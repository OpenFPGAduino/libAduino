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
    if(angle > 180) angle = 180;
    if(angle < 0)   angle = 0; 
    float ms =  0.5 + angle / 180.0 * 2;  //0.5ms + 2ms/180deg
    int pwm_with = ms / 20.0 * 2048;	
    STEERING_PWM_ANGLE = pwm_with;
}



