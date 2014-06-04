/**
 * @file exit.c 
 * @brief  ����ʹ���ж�
 *  
 */

 #include "exit.h"

static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	/**/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/*�����ж�Դ*/
	NVIC_InitStructure.NVIC_IRQChannel = EXIT0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_init(&NVIC_InitStructure);
}
