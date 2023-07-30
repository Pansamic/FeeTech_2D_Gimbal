#include <iostream>
#include <feetech_2d_gimbal.h>

SMS_STS ServoDriver;



/**
 * @brief initialize the serial port defined in feetech_2d_gimbal.h
*/
void Gimbal_Init(void)
{
    if(!ServoDriver.begin(1000000, SERIAL_PORT)){
        std::cout<<"Failed to init sms/sts motor!"<<std::endl;
        return ;
    }
}


/**
 * @brief set 2d gimbal yaw and pitch angle
 * @param YawAngle: 
 * @param PitchAngle:
*/
void Gimbal_SetAngle(float YawAngle, float PitchAngle)
{
	/* convert angle(unit: degree) to servo resolution */
	unsigned short Servo1Res = (unsigned int)(YawAngle * MOTOR_RESOLUTION / 360.0f);
	unsigned short Servo2Res = (unsigned int)(PitchAngle * MOTOR_RESOLUTION / 360.0f);

	/**
	 * @param ServoID The ID of the servo that controls the yaw angle is 1
	 * @param Position the target position resolution
	 * @param Velocity motor rotate in speed of 2400(unknown unit)
	 * @param Acceleration rotating acceleration
	*/
	ServoDriver.WritePosEx(1, Servo1Res, 4000, 500);
	ServoDriver.WritePosEx(2, Servo2Res, 4000, 500);
}

/**
 * @brief set horizontal angle
*/
void Gimbal_SetYaw(float Angle)
{
	/* convert angle(unit: degree) to servo resolution */
	unsigned short ServoRes = (unsigned int)(Angle * MOTOR_RESOLUTION / 360.0f);

	/**
	 * @param ServoID The ID of the servo that controls the yaw angle is 1
	 * @param Position the target position resolution
	 * @param Velocity motor rotate in speed of 2400(unknown unit)
	 * @param Acceleration rotating acceleration
	*/
	ServoDriver.WritePosEx(1, ServoRes, 4000, 500);
}


/**
 * @brief set vertical angle
*/
void Gimbal_SetPitch(float Angle)
{
	/* convert angle(unit: degree) to servo resolution */
	unsigned short ServoRes = (unsigned int)(Angle * MOTOR_RESOLUTION / 360.0f);

	/**
	 * @param ServoID The ID of the servo that controls the pitch angle is 2
	 * @param Position the target position resolution 
	 * @param Velocity motor rotate in speed of 2400(unknown unit)
	 * @param Acceleration rotating acceleration
	*/
	ServoDriver.WritePosEx(1, ServoRes, 4000, 500);}

