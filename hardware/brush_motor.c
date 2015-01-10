/*
 * brush_motor.c
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */
#include "brush_motor.h"
#include "FPGA.h"
#define BRUSHMOTOR_CTRL_ADDRESS brushmotor_address//0x260
#define BRUSHMOTOR_ID            *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS)
#define BRUSHMOTOR_PWM_FREQUENCE *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+1)
#define BRUSHMOTOR_PWM_WIDTH     *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+2)
#define BRUSHMOTOR_ON_OFF        *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+3)
#define BRUSHMOTOR_FORWARD_BACK  *((volatile int*) BRUSHMOTOR_CTRL_ADDRESS+4)

void brush_motor_init(void* brushmotor_address, int frequence ,int duty_cycle)
{
	BRUSHMOTOR_PWM_FREQUENCE = frequence * 0x100000000 / 200000000;
	usleep(50);
	BRUSHMOTOR_PWM_WIDTH = 0xFFFFFFFF / 100 * duty_cycle;
	usleep(50);
	BRUSHMOTOR_FORWARD_BACK = 1;
	usleep(50);
	BRUSHMOTOR_ON_OFF = 1;
	usleep(50);
}

void brush_motor_forward(void* brushmotor_address)
{
	BRUSHMOTOR_FORWARD_BACK = 1;
	usleep(50);
}

void brush_motor_back(void* brushmotor_address)
{
	BRUSHMOTOR_FORWARD_BACK=0;
	usleep(50);
}

void brush_motor_ON(void* brushmotor_address)
{
	BRUSHMOTOR_ON_OFF = 1;
	usleep(50);
}

void brush_motor_OFF(void* brushmotor_address)
{
	BRUSHMOTOR_ON_OFF = 0;
	usleep(50);
}

void brush_motor_set_pwm(void* brushmotor_address, unsigned int pwm)
{
	BRUSHMOTOR_PWM_WIDTH = pwm;
	usleep(50);
}


