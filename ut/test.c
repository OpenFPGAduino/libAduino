#include <stdio.h>
#include "unity.h"
#include "../api/openfpgaduino.h"

void setUp(void)
{
  /* This is run before EACH TEST */
  printf("setup\n");
}

void tearDown(void)
{
  printf("teardown\n");
}


void AM2301_ut()
{
    printf("Temperature is %.2f C", am2301_temperature(0));
    printf("\tTemperature is %.2f C\n", am2301_moisture(0));
    printf("Moisture is %.2f%%", am2301_temperature(1));
    printf("\tMoisture is %.2f%% \n", am2301_moisture(1));
}

void steering_ut()
{
    steering(0,15);
    steering(1,90);
}

int main()
{
    UnityBegin("libAduino");
    RUN_TEST(AM2301_ut);
    RUN_TEST(steering_ut);
    return (UnityEnd());
}
