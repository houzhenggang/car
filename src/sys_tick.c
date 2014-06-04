#include "sys_tick.h"

void SysTick_us_Init(void){
    if (SysTick_Config(SystemCoreClock / 1000000)) { /*1us�ж�һ��*/
while(1); /*���ò��ɹ���������ѭ��*/
    }
    SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk; /*�رյδ�ʱ������Ҫ��ʱ����*/
}

u32 nTime;

void Delay_us(u32 DelayTime){
    SysTick_us_Init();
		nTime=DelayTime;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;   /*�����δ�ʱ��*/
    while (nTime != 0) {;}
	}		

void TimingDelay_Decrement(void){
    if (nTime != 0) {
        nTime--;
    }
}

