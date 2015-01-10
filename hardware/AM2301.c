/*
 * AM2301.c
 *
 *  Created on: Oct 26, 2012
 *      Author: lizhizhou
 */
#include <stdint.h>
#include "FPGA.h"
#include "AM2301.h"
#define AM2301_ADDRESS AM2301_address//0x220
#define AM2301_ID      *((volatile int*) AM2301_address+1)
#define AM2301_DATA    *((volatile int*) AM2301_address+3)
#define AM2301_READY   *((volatile int*) AM2301_address+4)

void AM2301_init(void* AM2301_address)
{
//	  printf("AM2301 ID   =0x%x\n", AM2301_ID);
//	  printf("AM2301_DATA =0x%x\n", AM2301_DATA);
//	  printf("AM2301_READY=0x%x\n", AM2301_READY);
//	  printf("Moisture=%.1f%%\n", AM2301_get_moisture(AM2301_address));
//	  printf("Temperature=%.1fC\n", AM2301_get_temperature(AM2301_address));
}

float AM2301_get_temperature(void* AM2301_address)
{
	  short temperature_data;
	  int   sign;
	  float temperature;
	  while(AM2301_READY!=1);
	  sign             = 0x1 & (AM2301_DATA>>15);
	  temperature_data = 0x7fff & AM2301_DATA;
	  if (sign)
		  temperature  = temperature_data/-10.0;
	  else
		  temperature  = temperature_data/10.0;
	  return (temperature);
}

float AM2301_get_moisture(void* AM2301_address)
{
	  short moisture_data;
	  float moisture;
	  while(AM2301_READY!=1);
	  moisture_data    =  AM2301_DATA >> 16;
	  moisture     = moisture_data/10.0;
	  return (moisture);
}
