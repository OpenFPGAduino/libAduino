/*
 * Step_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou LI
 */
#include "step_motor.h"
#include "FPGA.h"
#include <unistd.h>
#include <math.h>
#define TIME_DELAY 5000
#define STEPMOTOR_CTRL_ADDRESS stepmotor_address
#define STEPMOTOR_PWM_FREQUENCE *((volatile int*) STEPMOTOR_CTRL_ADDRESS)
#define STEPMOTOR_PWM_WIDTH_A   *((volatile int*) STEPMOTOR_CTRL_ADDRESS+1)
#define STEPMOTOR_PWM_WIDTH_B   *((volatile int*) STEPMOTOR_CTRL_ADDRESS+2)
#define STEPMOTOR_STEP          *((volatile int*) STEPMOTOR_CTRL_ADDRESS+3)
#define STEPMOTOR_FORWARD_BACK  *((volatile int*) STEPMOTOR_CTRL_ADDRESS+4)
#define STEPMOTOR_ON_OFF        *((volatile int*) STEPMOTOR_CTRL_ADDRESS+5)
static int time_delay;
void step_motor_init(void* stepmotor_address, unsigned int frequence, unsigned int duty_cycle)
{
	STEPMOTOR_PWM_FREQUENCE = frequence * 0x100000000 / 200000000;
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle;
    STEPMOTOR_ON_OFF = 1;
    time_delay = TIME_DELAY;
}

void step_motor_set_delay(int u_second)
{
	time_delay = u_second;
}

int step_motor_get_delay()
{
	return (time_delay);
}

void step_motor_on(void* stepmotor_address)
{
    STEPMOTOR_ON_OFF = 1;
}

void step_motor_off(void* stepmotor_address)
{
    STEPMOTOR_ON_OFF = 0;
}

void step_motor_move_step_forward(void* stepmotor_address)
{
	STEPMOTOR_FORWARD_BACK=1;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
    usleep(time_delay);
}

void step_motor_move_step_back(void* stepmotor_address)
{
	STEPMOTOR_FORWARD_BACK=0;
	STEPMOTOR_STEP=1;
	STEPMOTOR_STEP=0;
    usleep(time_delay);
}

void setp_motor_subdivision(void* stepmotor_address, unsigned int substep,
		unsigned int division, unsigned int duty_cycle)
{
	unsigned int delta;
	if (substep > division)
		return;
	delta = 0xFFFFFFFF / 100 * duty_cycle / division * (division - 2 * substep);
	STEPMOTOR_PWM_WIDTH_A = 0xFFFFFFFF / 100 * duty_cycle - delta ;
	STEPMOTOR_PWM_WIDTH_B = 0xFFFFFFFF / 100 * duty_cycle + delta ;
}

