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
#define SERVO1_MIDPOINT 1040
#define SERVO2_MIDPOINT 1150
#define BAUDRATE 115200
#define AMPLITUDE 4096
int main(void)
{
	/* a factor that control the sin and cos */
	float factor = 0.0f;
    if(!ServoDriver.begin(BAUDRATE, SERIAL_PORT))
	{
        std::cout<<"Failed to init servo!"<<std::endl;
        return -1;
    }
	while(1)
	{
		ServoDriver.WritePosEx(1,100*sinf(factor)+SERVO1_MIDPOINT,2000,254);
		ServoDriver.WritePosEx(2,100*cosf(factor)+SERVO2_MIDPOINT,2000,254);
		factor += 0.016;
		// usleep(100000);
	}
	ServoDriver.end();
	return 1;	
}