/*
 * fan_motor.h
 *
 *  Created on: Nov 11, 2012
 *      Author: lizhizhou
 */

#ifndef FAN_MOTOR_H_
#define FAN_MOTOR_H_
extern void fan_motor_init(void* fan_address, int frequent, int duty_cycle);
extern void fan_ON(void* fan_address);
extern void fan_OFF(void* fan_address);
extern void fan_motor_set_pwm(void* fan_address, unsigned int pwm);

#endif /* FAN_MOTOR_H_ */
