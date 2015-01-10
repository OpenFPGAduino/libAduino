/*
 * sht1x.c
 *
 *  Created on: Jun 11, 2013
 *      Author: cowin
 */
#include <stdint.h>
#include "FPGA.h"
#include "sht1x.h"
#define SHT1X_ADDRESS  sht1x_address
#define SHT1X_ID      *((volatile int*) sht1x_address+1)
#define SHT1X_TEMP_DATA    *((volatile int*) sht1x_address+2)
#define SHT1X_MOIS_DATA    *((volatile int*) sht1x_address+3)
#define SHT1X_READY   *((volatile int*) sht1x_address+4)

void sht1x_init(void* sht1x_address)
{
    printf("ID is 0x%x\n", SHT1X_ID);
    printf("SHT1X_TEMP_DATA is %d\n", SHT1X_TEMP_DATA);
    printf("SHT1X_MOIS_DATA is %d\n", SHT1X_MOIS_DATA);
}

float sht1x_get_temperature(void* sht1x_address)
{
    float temperature;
    //while(SHT1X_READY!=1);
    temperature = -40.1 + SHT1X_TEMP_DATA * 0.01;
    return (temperature);
}

float sht1x_get_moisture(void* sht1x_address)
{
    short moisture_data;
    float linear_moisture;
    float moisture;
    float temperature = sht1x_get_temperature(sht1x_address);
    //while(SHT1X_READY!=1);
    moisture_data    =  SHT1X_MOIS_DATA;
    linear_moisture     = -2.0468 + 0.0367 * moisture_data +
            -1.5955E-6 * moisture_data * moisture_data;
    moisture = (temperature - 25) *(0.01 + 0.00008 * moisture_data)
            + linear_moisture;
    return (moisture);
}

