/***********************************************************************
 * @brief this is a demo program of FeeTech_2D_Gimbal project. First,
 * please setup a laser on the top of gimbal and place the gimbal 2 
 * meter away from a wall.
 * 
 *
***********************************************************************/
#include <iostream>
#include <math.h>
#include <SCServo.h>

/* servo driver instance */
SMS_STS ServoDriver;

#define SERIAL_PORT "/dev/ttyUSB0"
#define SERVO1_OFFSET 850
#define SERVO2_OFFSET 230
#define BAUDRATE 115200
int main(void)
{
	/* a factor that control the sin and cos */
	float factor = 0.0f;
    if(!ServoDriver.begin(BAUDRATE, SERIAL_PORT)){
        std::cout<<"Failed to init servo!"<<std::endl;
        return -1;
    }
	while(1)
	{
		ServoDriver.WritePosEx(1,sinf(factor),65535,254);
		ServoDriver.WritePosEx(2,cosf(factor),65535,254);
		factor += 0.01;
	}
	ServoDriver.end();
	return 1;
}