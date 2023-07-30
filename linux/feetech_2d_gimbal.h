#ifndef __FEETECH_2D_GIMBAL_H__
#define __FEETECH_2D_GIMBAL_H__

#include <SCServo.h>
/******************************************************************/
/*                             MACROS                             */
/******************************************************************/
#define SERIAL_PORT "/dev/ttyUSB0"
#define MOTOR_RESOLUTION 4096

/******************************************************************/
/*                             EXTERN                             */
/******************************************************************/


/******************************************************************/
/*                     FUNCTION DECLARATION                       */
/******************************************************************/
void Gimbal_Init(void);
void Gimbal_SetAngle(float YawAngle, float PitchAngle);
void Gimbal_SetYaw(float Angle);
void Gimbal_SetPitch(float Angle);
void Gimbal_Release(void);

#endif