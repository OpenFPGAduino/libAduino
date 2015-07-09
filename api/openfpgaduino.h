#ifndef OPENFGPADUINO_H_
#define OPENFGPADUINO_H_

//Functionality: Open the recourse in FPGA, call in the begin of main
int fpga_open();

//Functionality: Close the recourse in FPGA
void fpga_close();

//Functionality: Open the shield IO
void shield_ctrl_init();

//Functionality: Control the led
//Argument:
//id: The id of led can be 0-3
//r: The red color of led
//g: The greem color of led
//b: The blue color of led
void led(int id, char r, char g, char b);
//Functionality: Get the temperatue
//Argument:
//id: The id of AM2302 can be 0-1
float am2301_temperature(int id);

//Functionality: Get the moisture
//Argument:
//id: The id of AM2302 can be 0-1
float am2301_moisture(int id);

//Functionality: Control the digital IO port
//Argument:
//id: use 0-26
//value: Can be 1 or 0
void dio_a(int id, int value);

//Functionality: Control the digital IO port
//Argument:
//id: use 0-26
//value: Can be 1 or 0
void dio_b(int id, int value);

//Functionality: Open the Analog IO A
void ain_a_init();

//Functionality: Open the Analog IO B
void ain_b_init();

//Functionality: Get the analog port value
//Argument:
//id: use 1-8
int ain_a(int id);

//Functionality: Get the analog port value
//Argument:
//id: use 1-8
int ain_b(int id);

//Functionality: print the string to the console
//Argument:
//format:output format string
int print(const char* format, ...);

//Functionality: Sleep for seconds
//Argument:
//seconds The seconds for sleeping
unsigned int sleep(unsigned int seconds);

//Functionality: Sleep for micro seconds
//Argument:
//usecods: The micro seconds for sleeping
int usleep(unsigned int useconds);

#endif /* OPENFGPADUINO_H_ */
