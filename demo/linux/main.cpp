#include <iostream>
#include <feetech_2d_gimbal.h>

int main(int argc, char **argv)
{
	Gimbal_Init();
	while(1)
	{
		Gimbal_SetYaw(0);
		usleep(2187*1000);
		Gimbal_SetYaw(90);
		usleep(2187*1000);
	}
	Gimbal_Release();
	return 1;
}