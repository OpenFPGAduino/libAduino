/*
 * PIO26.h
 *
 *  Created on: Oct 25, 2012
 *      Author: Zhizhou Li
 */

#ifndef PIO26_H_
#define PIO26_H_

#include"FPGA.h"

#define IOA_ADDRESS   0x0
#define IOA_BASE      (IOA_ADDRESS/4)
#define IOA           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define IOA_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define IOA_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define IOA_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define IOA_IO_BASE   16
#define IOA_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define IOA_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define IOA_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define IOA_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define IOA_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define IOA_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define IOA_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define IOA_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)
#define IOA_IO_8      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+8)
#define IOA_IO_9      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+9)
#define IOA_IO_10     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+10)
#define IOA_IO_11     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+11)
#define IOA_IO_12     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+12)
#define IOA_IO_13     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+13)
#define IOA_IO_14     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+14)
#define IOA_IO_15     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+15)
#define IOA_IO_16     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+16)
#define IOA_IO_17     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+17)
#define IOA_IO_18     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+18)
#define IOA_IO_19     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+19)
#define IOA_IO_20     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+20)
#define IOA_IO_21     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+21)
#define IOA_IO_22     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+22)
#define IOA_IO_23     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+23)
#define IOA_IO_24     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+24)
#define IOA_IO_25     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+25)


#define IOB_ADDRESS   0x80
#define IOB_BASE      (IOB_ADDRESS / 4)
#define IOB           *((volatile int*)  FPGA_MOD_BASE+IOB_BASE)
#define IOB_ID        *((volatile int*)  FPGA_MOD_BASE+IOB_BASE+ 1)
#define IOB_DATA      *((volatile int*)  FPGA_MOD_BASE+IOB_BASE+ 2)
#define IOB_OE        *((volatile int*)  FPGA_MOD_BASE+IOB_BASE+ 4)
#define IOB_IO_BASE   16
#define IOB_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE))
#define IOB_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+1)
#define IOB_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+2)
#define IOB_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+3)
#define IOB_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+4)
#define IOB_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+5)
#define IOB_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+6)
#define IOB_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+7)
#define IOB_IO_8      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+8)
#define IOB_IO_9      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+9)
#define IOB_IO_10     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+10)
#define IOB_IO_11     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+11)
#define IOB_IO_12     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+12)
#define IOB_IO_13     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+13)
#define IOB_IO_14     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+14)
#define IOB_IO_15     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+15)
#define IOB_IO_16     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+16)
#define IOB_IO_17     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+17)
#define IOB_IO_18     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+18)
#define IOB_IO_19     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+19)
#define IOB_IO_20     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+20)
#define IOB_IO_21     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+21)
#define IOB_IO_22     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+22)
#define IOB_IO_23     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+23)
#define IOB_IO_24     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+24)
#define IOB_IO_25     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+25)
#endif /* PIO26_H_ */
