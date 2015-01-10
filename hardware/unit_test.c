#include <stdio.h>
#include <unistd.h>
#include "platform.h"
#include "led.h"

void AM2301_test()
{
    AM2301_init(AM2301_0);
    AM2301_init(AM2301_1);
    while(1)
    {
        sleep(1);
        printf("Temperature is %.2f C", AM2301_get_temperature(AM2301_0));
        printf("\tTemperature is %.2f C\n", AM2301_get_temperature(AM2301_1));
        printf("Moisture is %.2f%%", AM2301_get_moisture(AM2301_0));
        printf("\tMoisture is %.2f%% \n", AM2301_get_moisture(AM2301_1));
    }
}

void step_motmor_test()
{
    int i;
    step_motor_init(STEP_MOTOR_0, 50000, 20);
    step_motor_init(STEP_MOTOR_1, 50000, 20);
    step_motor_init(STEP_MOTOR_2, 50000, 20);
    step_motor_init(STEP_MOTOR_3, 10000, 30);
    for(i = 0; i < 1000; i++) {
        step_motor_move_step_forward(STEP_MOTOR_0);
        step_motor_move_step_forward(STEP_MOTOR_1);
        step_motor_move_step_forward(STEP_MOTOR_2);
        step_motor_move_step_forward(STEP_MOTOR_3);
    }
    for(i = 0; i < 1000; i++) {
        step_motor_move_step_back(STEP_MOTOR_0);
        step_motor_move_step_back(STEP_MOTOR_1);
        step_motor_move_step_back(STEP_MOTOR_2);
        step_motor_move_step_back(STEP_MOTOR_3);
    }

}

void brush_motor_test()
{
    brush_motor_init(BRUSH_MOTOR_0, 1000, 30);
    brush_motor_init(BRUSH_MOTOR_1, 1000, 30);
    brush_motor_back(BRUSH_MOTOR_1);
    brush_motor_init(BRUSH_MOTOR_2, 1000, 30);
    brush_motor_init(BRUSH_MOTOR_3, 1000, 30);
}

void PID_test()
{
    int i;
    float target =100;
    float current = 0;
    float current_d =0;
    float current_d_d = 0;
    float error;
    float error_d;
    float error_d_d;
    for(i=0; i < 100; i++)
    {
        current_d_d = current_d;
        current_d = current;
        error_d_d = error_d;
        error_d = error;
        error = target - current_d_d;
        current = current + PID(error, error_d, error_d_d, 0.2, 0.01, 0.03);
        printf("current is %f\n",current);
    }
}

void PIO_test()
{
    IOA_OE      = 0xffffffff;  // init IO
    IOB_OE      = 0xffffffff;  // init IO
    IOA_IO_0    = 0;
    IOB_IO_0    = 1;
    IOA_IO_1    = 0;
    IOB_IO_1    = 1;
}

void subdivision_step_motor_test()
{
	int i;
	step_motor_init(SUBDIVISION_STEP_MOTOR_0, 10000, 30);
	step_motor_move_step_back(SUBDIVISION_STEP_MOTOR_0);
	while(1) {
		for (i = 0; i< 64 ; i++) {
			setp_motor_subdivision(SUBDIVISION_STEP_MOTOR_0, i, 64 ,30);
			usleep(100000);
		}
		for (i = 64; i >=0 ; i--) {
			setp_motor_subdivision(SUBDIVISION_STEP_MOTOR_0, i, 64 ,30);
			usleep(100000);
		}
	}
}

void led_unit_test(void)
{
	set_rgb_led(LED_0, 255, 0 , 0);
	set_rgb_led(LED_1, 0, 255 , 0);
	set_rgb_led(LED_2, 0, 0 , 255);
}


