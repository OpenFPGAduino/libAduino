/*
 * position_sensor.c
 *
 *  Created on: 2012-10-30
 *      Author: Zhizhou Li
 */

#include "FPGA.h"
#define POSITITON_SENSOR_ADDRESS sensor_address //0x280
#define POSITITON_SENSOR_ADDRESS_ID           *((volatile int*) POSITITON_SENSOR_ADDRESS)
#define POSITITON_SENSOR_ADDRESS_POSTITION    *((volatile int*) POSITITON_SENSOR_ADDRESS+1)
#define POSITITON_SENSOR_ADDRESS_DIRECTION    *((volatile int*) POSITITON_SENSOR_ADDRESS+2)

int get_position(void* sensor_address)
{
	return POSITITON_SENSOR_ADDRESS_POSTITION;
}

int get_direction(void* sensor_address)
{
	return POSITITON_SENSOR_ADDRESS_DIRECTION;
}
