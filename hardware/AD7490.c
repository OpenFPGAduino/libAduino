/*
 * AD7490.c
 *
 *  Created on: Jan 17, 2015
 *      Author: zhizhouli
 */

#include "FPGA.h"
#include "AD7490.h"
#define AD7490_ADDRESS         AD7490_address
#define AD7490_ID              *((volatile int*)   AD7490_ADDRESS+1)
#define AD7490_ADC_CTRL        *((volatile int*)   AD7490_ADDRESS+2)
#define AD7490_RESET           *((volatile char*)  &AD7490_ADC_CTRL+0)
#define AD7490_CODING          *((volatile char*)  &AD7490_ADC_CTRL+1)
#define AD7490_RANG            *((volatile char*)  &AD7490_ADC_CTRL+2)
#define AD7490_CONVERTING_ADC  *((volatile char*)  &AD7490_ADC_CTRL+3)
#define AD7490_CNV_DELAY       *((volatile int*)   AD7490_ADDRESS+3)
#define AD7490_CH_BASE         *((volatile short*) AD7490_ADDRESS+8)

void AD7490_reset(void* AD7490_address)
{
	AD7490_RESET = 1;
	AD7490_RESET = 0;
}

void AD7490_init(void* AD7490_address)
{
	AD7490_reset(AD7490_address);
	AD7490_CNV_DELAY = 255;
	AD7490_RANG = 0;   //0 for 0-2* Vref 1 fpr 0-Vref
	AD7490_CODING = 1; //1 for Natural Binary 2 for Twos Complement
}

uint16_t AD7490_get_data(void* AD7490_address, int channel)
{
	if(channel < 0 || channel > 15)
		return (0);
	uint16_t data = *(&AD7490_CH_BASE + channel);
	return (0xfff & data);  //12bit ADC data;
}
