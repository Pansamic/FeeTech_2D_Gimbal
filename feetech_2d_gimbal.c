#ifdef __cplusplus
extern "C" {
#endif
#include <SCServo.h>
#include <feetech_2d_gimbal.h>
SMS_STS sm_st;



/**
 * 
*/
void Gimbal_Init(void)
{

}


/**
 * @brief set 2d gimbal yaw and pitch angle
 * @param YawAngle: 
 * @param PitchAngle:
*/
void Gimbal_SetAngle(float YawAngle, float PitchAngle)
[

]





int main(int argc, char **argv)
{
	if(argc<2){
        std::cout<<"argc error!"<<std::endl;
        return 0;
	}
	std::cout<<"serial:"<<argv[1]<<std::endl;
    if(!sm_st.begin(1000000, argv[1])){
        std::cout<<"Failed to init sms/sts motor!"<<std::endl;
        return 0;
    }
	while(1){
		sm_st.WritePosEx(1, 4095, 2400, 50);//舵机(ID1)以最高速度V=2400(步/秒)，加速度A=50(50*100步/秒^2)，运行至P1=4095位置
		std::cout<<"pos = "<<4095<<std::endl;
		usleep(2187*1000);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
  
		sm_st.WritePosEx(1, 0, 2400, 50);//舵机(ID1)以最高速度V=2400(步/秒)，加速度A=50(50*100步/秒^2)，运行至P0=0位置
		std::cout<<"pos = "<<0<<std::endl;
		usleep(2187*1000);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
	}
	sm_st.end();
	return 1;
}


#ifdef __cplusplus
}
#endif