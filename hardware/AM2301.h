/*
 * AM2301.h
 *
 *  Created on: Oct 26, 2012
 *      Author: lizhizhou
 */

#ifndef AM2301_H_
#define AM2301_H_

extern void AM2301_init(void* AM2301_address);
extern float AM2301_get_temperature(void* AM2301_address);
extern float AM2301_get_moisture(void* AM2301_address);

#endif /* AM2301_H_ */
