/** 
 * @file led.c 
 * @brief 
 *  
 * @attention 
 *  
 * led��Ӧ��GPIO����
 * LED1 PB0
 * LED2 PF7
 * LED3 PF8 
 */ 

#include "led.h"

/**
 * @brief ��ʼ������LED��IO
 * @param 
 * @retval 
 * @return 
 * @author k1 (2014/5/28)
 */
void LED_GPIO_Config(void){

    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

    /*��������ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /*PB0 ������� 50MHz*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    /*��ʼ��GPIO0*/
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /*�ر�led��*/
    GPIO_SetBits(GPIOB, GPIO_Pin_0);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOF, &GPIO_InitStructure); 

    GPIO_SetBits(GPIOF, GPIO_Pin_7 | GPIO_Pin_8);
}
