/***********************************************************************
 * @brief this is a demo program of FeeTech_2D_Gimbal project. First,
 * please setup a laser on the top of gimbal and place the gimbal 2 
 * meter away from a wall.
 * 
 *
***********************************************************************/
#include <iostream>
#include <math.h>
#include <feetech_2d_gimbal.h>

/* the distance between gimbal and wall */
#define DISTANCE 1

int main(int argc, char **argv)
{
	/* a factor that control the sin and cos */
	float factor = 0.0f;

	Gimbal_Init();
	Gimbal_SetAngle(0,0);
	std::cout<<"gimbal has set to yaw=0 and pitch=0."<<std::endl<<"place gimbal towards wall and type 'y' to start!"<<std::endl;
	while(getchar()!='y');
	std::cout<<"gimbal start to draw circle"<<std::endl;
	while(1)
	{
		Gimbal_SetAngle(sinf(factor),cos(factor));
		factor+=0.1f;
	}
	Gimbal_Release();
	return 1;
}