/*
 * SCServo.c
 * ���ض��Ӳ���ӿڲ����
 * ����: 2022.1.6
 * ����: 
 */

#include "stm32f10x.h"
#include "uart.h"

uint32_t IOTimeOut = 5000;//ͨ�ų�ʱ
uint8_t wBuf[128];
uint8_t wLen = 0;

//UART �������ݽӿ�
int readSCS(unsigned char *nDat, int nLen)
{
	int Size = 0;
	int ComData;
	uint32_t t_user = 0;
	while(1){
		ComData = Uart_Read();
		if(ComData!=-1){
			if(nDat){
				nDat[Size] = ComData;
			}
			Size++;
			t_user = 0;
		}
		if(Size>=nLen){
			break;
		}
		t_user++;
		if(t_user>IOTimeOut){
			break;
		}
	}
	return Size;
}

//UART �������ݽӿ�
int writeSCS(unsigned char *nDat, int nLen)
{
	while(nLen--){
		if(wLen<sizeof(wBuf)){
			wBuf[wLen] = *nDat;
			wLen++;
			nDat++;
		}
	}
	return wLen;
}

//�����л���ʱ
void SCSDelay(void)
{
	uint8_t i = 30;
	while(i--){}//0.056*i(us)
}

//���ջ�����ˢ��
void rFlushSCS()
{
	SCSDelay();
	Uart_Flush();
}

//���ͻ�����ˢ��
void wFlushSCS()
{
	if(wLen){
		Uart_Send(wBuf, wLen);
		wLen = 0;
	}
}
