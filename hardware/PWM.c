/*
 * PWM.c
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */
#include "PWM.h"
#include "FPGA.h"
#define PWM_CTRL_ADDRESS pwm_address//0x100
#define PWM_ID            *((volatile int*) PWM_CTRL_ADDRESS+1)
#define PWM_STATE         *((volatile int*) PWM_CTRL_ADDRESS+3)
#define PWM_GATE          *((volatile int*) PWM_CTRL_ADDRESS+3)
#define PWM_DUTYCYCLE     *((volatile int*) PWM_CTRL_ADDRESS+4)

#define PWM_RESET         *((volatile char*) PWM_STATE)
#define PWM_OUT_INV       *((volatile char*) PWM_STATE+1)
#define PWM_DUTYCYCLE_EN  *((volatile char*) PWM_STATE+2)
#define PWM_GATE_EN       *((volatile char*) PWM_STATE+3)

void PWM_init(void* pwm_address)
{
	PWM_RESET   = 0;
	PWM_OUT_INV = 0;
}

void PWM_SET_GATE(void* pwm_address, unsigned int gate)
{
	PWM_GATE    = gate;
}

void PWM_SET_DUTY_CYCLE(void* pwm_address, unsigned int duty)
{
	PWM_DUTYCYCLE = duty;
}
