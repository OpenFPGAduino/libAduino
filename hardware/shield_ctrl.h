/*
 * shield_ctrl.h
 *
 *  Created on: Oct 25, 2012
 *      Author: Zhizhou Li
 */

#ifndef SHIELD_CTRL_H_
#define SHIELD_CTRL_H_

#define SHIELD_CTRL_ADDRESS 0x200
#define SHIELD_CTRL_BASE    (SHIELD_CTRL_ADDRESS/4)
#define SHIELD_CTRL    *((volatile int*) FPGA_SYS_BASE+SHIELD_CTRL_BASE)

extern void shield_ctrl_init();

#endif /* SHIELD_CTRL_H_ */
