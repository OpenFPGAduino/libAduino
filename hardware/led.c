/*
 * led.c
 *
 *  Created on: Jul 15, 2013
 *      Author: zhizhouli
 */
#include <stdint.h>
#include "FPGA.h"
#include "led.h"
#define LED_ADDRESS  led_address
#define LED_DATA      *((volatile int*) led_address)
void set_rgb_led(void* led_address, char r, char g, char b)
{
	unsigned int i=0x0;
	i = r + (g << 8) + (b << 16);
	LED_DATA = i;
	return;
}
