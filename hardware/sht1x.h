/*
 * sht1x.h
 *
 *  Created on: Jun 11, 2013
 *      Author: cowin
 */

#ifndef SHT1X_H_
#define SHT1X_H_

extern void sht1x_init(void* sht1x_address);
extern float sht1x_get_temperature(void* sht1x_address);
extern float sht1x_get_moisture(void* sht1x_address);

#endif /* SHT1X_H_ */
