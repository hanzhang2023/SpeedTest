#include "usart.h"   // 相当于51单片机中的  #include <reg51.h>
void Usart1_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitSturcture;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
    
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    USART_InitSturcture.USART_BaudRate=100000;
    USART_InitSturcture.USART_HardwareFlowControl=DISABLE;
    USART_InitSturcture.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
    USART_InitSturcture.USART_Parity=USART_Parity_No;
    USART_InitSturcture.USART_StopBits=USART_StopBits_1;
    USART_InitSturcture.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART1,&USART_InitSturcture);

}
//串口屏串口初始化
void Usart2_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitSturcture;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    USART_InitSturcture.USART_BaudRate=100000;
    USART_InitSturcture.USART_HardwareFlowControl=DISABLE;
    USART_InitSturcture.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
    USART_InitSturcture.USART_Parity=USART_Parity_No;
    USART_InitSturcture.USART_StopBits=USART_StopBits_1;
    USART_InitSturcture.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART2,&USART_InitSturcture);

}

//调试串口
void Usart3_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitSturcture;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    USART_InitSturcture.USART_BaudRate=100000;
    USART_InitSturcture.USART_HardwareFlowControl=DISABLE;
    USART_InitSturcture.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
    USART_InitSturcture.USART_Parity=USART_Parity_No;
    USART_InitSturcture.USART_StopBits=USART_StopBits_1;
    USART_InitSturcture.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART3,&USART_InitSturcture);

}

void USART_DataSend(void)
{
    USART_SendData(USART3,200);
}
