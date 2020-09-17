#ifndef __TIM_H
#define __TIM_H

#include "stm32f4xx.h"

#define  BASIC_TIM						TIM6
#define  BASIC_TIM_CLK  			RCC_APB1Periph_TIM6
#define  BASIC_TIM_IRQn 			TIM6_DAC_IRQn
#define  BASIC_TIM_IRQHandler TIM6_DAC_IRQHandler

extern unsigned int _1msflag;

void TIMx_NVIC_Configuration(void);

void TIM_Mode_Config(unsigned short arr,unsigned short psc);


#endif
