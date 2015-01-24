/*
 * AD7490.h
 *
 *  Created on: Jan 17, 2015
 *      Author: zhizhouli
 */

#ifndef AD7490_H_
#define AD7490_H_

#include <stdint.h>
extern void AD7490_reset(void* AD7490_address);
extern void AD7490_init(void* AD7490_address);
extern uint16_t AD7490_get_data(void* AD7490_address, int channel);

#endif /* AD7490_H_ */
