#include "can.h"   // 相当于51单片机中的  #include <reg51.h>
//裁判系统can通讯初始化
void Can_Config(void)
{
    GPIO_InitTypeDef    GPIO_Initsturcture;
    CAN_InitTypeDef     CAN_Initstructure;
    CAN_FilterInitTypeDef   CAN_FilterInitStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    
    GPIO_Initsturcture.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_Initsturcture.GPIO_Pin=GPIO_Pin_12;//CAN1 TX
    GPIO_Initsturcture.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_Initsturcture);
    
    GPIO_Initsturcture.GPIO_Mode=GPIO_Mode_AF_OD;
    GPIO_Initsturcture.GPIO_Pin=GPIO_Pin_11;//CAN1 RX
    GPIO_Init(GPIOA,&GPIO_Initsturcture);
    
    CAN_Initstructure.CAN_ABOM=ENABLE;
    CAN_Initstructure.CAN_AWUM=ENABLE;
    CAN_Initstructure.CAN_BS1=3;
    CAN_Initstructure.CAN_BS2=2;
    CAN_Initstructure.CAN_Mode=CAN_Mode_Normal;
    CAN_Initstructure.CAN_NART=DISABLE;
    CAN_Initstructure.CAN_Prescaler=7;
    CAN_Initstructure.CAN_RFLM=DISABLE;
    CAN_Initstructure.CAN_SJW=1;
    CAN_Initstructure.CAN_TTCM=DISABLE;
    CAN_Initstructure.CAN_TXFP=DISABLE;
    CAN_Init(CAN1,&CAN_Initstructure);
    
    CAN_FilterInitStructure.CAN_FilterNumber = 0;
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
	CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
	CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
	CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
	CAN_FilterInit(&CAN_FilterInitStructure);
    
}


