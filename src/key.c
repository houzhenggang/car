/**
 * @file key.c 
 * @brief ɨ�� 
 */

#include "key.h"

static void Delay(__IO u32 ncount) /*����ȷ��ʱ*/
{
    for (; ncount != 0; ncount--) 
	{;}
}

/**
 * @brief �����õ���IO�� KEY1 ��PA0�� 
 *                    KEY2 ��PC13��
 * @author k1 (2014/5/28)
 */
void key_gpio_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /*����ʱ��*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);

	/*��ʼ��PA1*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);          

	/*��ʼ��PC13*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &GPIO_InitStructure); 
}
/**
 * @brief ����Ƿ��м����� 
 * @param ����Ķ˿ں����� 
 *      @arg
 *      @arg
 * @retval ������״̬ 
 *      @arg
 *      @arg
 */
u8 key_scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)
{    
	/*����Ƿ��м�����*/
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) 
	{ 
		Delay(1000);/*��ʱ����*/
		if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) 
        {
            while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);/*�ȴ������ͷ�*/
            return KEY_ON;
        }
        else
            return KEY_OFF;
    }
    return KEY_OFF;
}
