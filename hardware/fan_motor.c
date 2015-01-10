/*
 * fan_motor.c
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#include "fan_motor.h"
#include "FPGA.h"
#define FANMOTOR_CTRL_ADDRESS fan_address
#define FANMOTOR_ID            *((volatile int*) FANMOTOR_CTRL_ADDRESS)
#define FANMOTOR_PWM_FREQUENCE *((volatile int*) FANMOTOR_CTRL_ADDRESS+1)
#define FANMOTOR_PWM_WIDTH     *((volatile int*) FANMOTOR_CTRL_ADDRESS+2)
#define FANMOTOR_ON_OFF        *((volatile int*) FANMOTOR_CTRL_ADDRESS+3)

void fan_motor_init(void* fan_address, int frequent, int duty_cycle)
{
	FANMOTOR_PWM_FREQUENCE = frequent * 0x100000000 / 200000000;
	usleep(50);
	FANMOTOR_PWM_WIDTH = 0xFFFFFFFF / 100 * duty_cycle;
	usleep(50);
	FANMOTOR_ON_OFF = 1; 
	usleep(50);
}

void fan_ON(void* fan_address)
{
	FANMOTOR_ON_OFF = 1; 
}

void fan_OFF(void* fan_address)
{
	FANMOTOR_ON_OFF = 0;
}

void fan_motor_set_pwm(void* fan_address, unsigned int pwm)
{
	FANMOTOR_PWM_WIDTH = pwm;
	usleep(50);
}
