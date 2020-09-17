#include "TIM.H"

unsigned int _1msflag=0;

void TIMx_NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void TIM_Mode_Config(unsigned short arr,unsigned short psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimBaseStructure;
	RCC_APB1PeriphClockCmd(BASIC_TIM_CLK,ENABLE);
	TIM_TimBaseStructure.TIM_Period=arr;
	TIM_TimBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseInit(BASIC_TIM,&TIM_TimBaseStructure);
	TIM_ClearFlag(BASIC_TIM,TIM_FLAG_Update);
	TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);
	TIM_Cmd(BASIC_TIM,ENABLE);
}

void BASIC_TIM_IRQHandler(void)
{
	if(TIM_GetITStatus(BASIC_TIM,TIM_IT_Update)!=RESET)
	{	
		_1msflag=1;
		TIM_ClearFlag(BASIC_TIM,TIM_FLAG_Update);
	}
}
