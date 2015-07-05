#include "../hardware/platform.h"
#include "../hardware/PIO26.h"
#include "../hardware/shield_ctrl.h"
#include "../hardware/FPGA.h"
#include "../hardware/AM2301.h"
#include "../hardware/sht1x.h"
#include "../hardware/position_sensor.h"
#include "../hardware/step_motor.h"
#include "../hardware/brush_motor.h"
#include "../hardware/fan_motor.h"
void led(int id, char r, char g, char b)
{
	void* address;
	switch (id) {
		case 0:
			address = LED_0;
			break;
		case 1:
			address = LED_1;
			break;
		case 2:
			address = LED_2;
			break;
		case 3:
			address = LED_3;
			break;
		default:
		    return;
	}
	set_rgb_led(address,r,g,b);
}

void dio_a(int id, int value)
{

}

void dio_b(int id, int value)
{

}

int ain_a(int id)
{
	//AD7490_init(ADC7490_0);
	return AD7490_get_data(ADC7490_0, id -1);
}

int ain_b(int id)
{
	//AD7490_init(ADC7490_1);
	return AD7490_get_data(ADC7490_1, id -1);
}

void pwm(int id, int pwm)
{
	//PWM_init();
	void* address;
	switch (id) {
		case 0:
			address = PWM_0;
			break;
		case 1:
			address = PWM_1;
			break;
		case 2:
			address = PWM_2;
			break;
		case 3:
			address = PWM_3;
			break;
		default:
		    return;
	}

}

float am2301_temperature(int id)
{
	void* address;
	switch (id) {
		case 0:
			address = AM2301_0;
			break;
		case 1:
			address = AM2301_1;
			break;
		default:
		    return 0;
	}
	return AM2301_get_temperature(address);
}

float am2301_moisture(int id)
{
	void* address;
	switch (id) {
		case 0:
			address = AM2301_0;
			break;
		case 1:
			address = AM2301_1;
			break;
		default:
		    return 0;
	}
	return AM2301_get_moisture(address);
}


