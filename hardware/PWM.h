/*
 * PWM.h
 *
 *  Created on: Nov 11, 2012
 *      Author: Zhizhou Li
 */

#ifndef PWM_H_
#define PWM_H_

extern void PWM_init(void* pwm_address);
extern void PWM_SET_GATE(void* pwm_address, unsigned int gate);
extern void PWM_SET_DUTY_CYCLE(void* pwm_address, unsigned int duty);

#endif /* PWM_H_ */
