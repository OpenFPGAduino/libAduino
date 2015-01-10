/*
 * brush_motor.h
 *
 *  Created on: Nov 6, 2012
 *      Author: Zhizhou Li
 */

#ifndef BRUSHMOTOR_H_
#define BRUSHMOTOR_H_


extern void brush_motor_init(void* brushmotor_address, int frequence ,int duty_cycle);
extern void brush_motor_forward(void* brushmotor_address);
extern void brush_motor_back(void* brushmotor_address);
extern void brush_motor_ON(void* brushmotor_address);
extern void brush_motor_OFF(void* brushmotor_address);
extern void brush_motor_set_pwm(void* brushmotor_address,
        unsigned int pwm);

#endif /* BRUSHMOTOR_H_ */
