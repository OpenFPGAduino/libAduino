/*
 * step_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_

extern void step_motor_init(void* stepmotor_address, unsigned int frequence, unsigned int duty_cycle);
extern void step_motor_set_delay(int u_second);
extern int step_motor_get_delay();
extern void step_motor_on(void* stepmotor_address);
extern void step_motor_off(void* stepmotor_address);
extern void step_motor_move_step_forward(void* stepmotor_address);
extern void step_motor_move_step_back(void* stepmotor_address);
extern void setp_motor_subdivision(void* stepmotor_address, unsigned int substep,
		unsigned int division, unsigned int duty_cycle);

#endif /* STEPMOTOR_H_ */
