/*
 * FPGA.h
 *
 *  Created on: Oct 25, 2012
 *      Author: Zhizhou Li
 */

#ifndef FPGA_H_
#define FPGA_H_

#define FPGA_QSYS_MOD_BASE 0x20000000
#define FPGA_QSYS_SYS_BASE 0x10000000
#define SYS_ID         *((volatile int*) FPGA_SYS_BASE)

#define QSYS_ADDRESS_TO_LINUX_ADDRESS(ADDRESS) \
	ADDRESS >= FPGA_QSYS_MOD_BASE ?             \
	FPGA_MOD_BASE + (ADDRESS - FPGA_QSYS_MOD_BASE)/4:FPGA_SYS_BASE + (ADDRESS - FPGA_QSYS_SYS_BASE)/4

extern int* FPGA_MOD_BASE;
extern int* FPGA_SYS_BASE;
extern int fpga_open();
extern void fpga_close();


#endif /* FPGA_H_ */
