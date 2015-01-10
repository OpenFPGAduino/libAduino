/*
 * ShieldCtrl.c
 *
 *  Created on: Oct 26, 2012
 *      Author: Zhizhou LI
 */
#include "shield_ctrl.h"
#include "FPGA.h"

void shield_ctrl_init()
{
	  SHIELD_CTRL = 0x03030300;
}
