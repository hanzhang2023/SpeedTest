#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "gpio.h"
#include "tim.h"
int a,b,t;
float v;
float l=5.1;//L=5.1cm=l*10^-2 m T=t*10^-4s  v=L/T=(l*10^-2)/(t*10^-4)=l/t*100 m/s
int main(void)
{
    RCC_ClocksTypeDef clock;
    Tim3Config();
    RCC_GetClocksFreq(&clock);

    GPIO_Config();
    while(1)
    {
        if(t<5000&&t>0)
        {
            v=l/t*100;
        }
    }
    
}


void EXTI1_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
    {
        EXTI_ClearFlag(EXTI_Line1);
        a=TIM3->CNT;
    }
    
}
void EXTI0_IRQHandler(void)
{
     if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
    {
        EXTI_ClearFlag(EXTI_Line0);
        b=TIM3->CNT;
    }
    if(a&&b !=0)
    {
        t=b-a;
    
    }

}
