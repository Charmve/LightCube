/**
  ******************************************************************************
  * @file    SM12126.c
  * $Author: SFZ $
  * $Revision: 1 $
  * $Date:: 2018-11-18 16:16:48 +0800 #$
  * @brief   主函数.
  ******************************************************************************
  * @attention
  *
  * 
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "SM12126.h"

/*******************************************************************************
* Function Name  : SM12126_GPIO_Init(void)
* Description    : SM12126芯片管脚初始化
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void SM12126_GPIO_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(SDI1_GPIO_CLK|SDI2_GPIO_CLK|SDI3_GPIO_CLK|CLK_GPIO_CLK|LE_GPIO_CLK|OE_GPIO_CLK , ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType= GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Pin  = SDI1_GPIO_PIN;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = SDI2_GPIO_PIN;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = SDI3_GPIO_PIN;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = CLK_GPIO_PIN;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	CLK = 0;
//	delay_us(1);
	
	GPIO_InitStructure.GPIO_Pin  = LE_GPIO_PIN;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	LE = 0;
//	delay_us(1);
	
	GPIO_InitStructure.GPIO_Pin  = OE_GPIO_PIN;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	OE = 1;
//	delay_us(1);
}

/*******************************************************************************
* Function Name  : WriteData(unsigned short Data16Bits_1,unsigned short Data16Bits_2,unsigned short Data16Bits_3)
* Description    : 给芯片写入一个16位数据，最高位先传输，对应OUT15-最高位，OUT14-次高位...OUT0-最低位
* Input          : 4位16进制数，0xXXXX
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void WriteData(unsigned char Data_A,unsigned char Data_B,unsigned char Data_C)
{
	SDI1 = Data_A;
	SDI2 = Data_B;
	SDI3 = Data_C;
//	delay_us(1);
	CLK = 1;
//	delay_us(1);
	CLK = 0;
//	delay_us(1);
}

/*******************************************************************************
* Function Name  : OpenLED(void)
* Description    : 打开锁存器，并输出
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void OpenLED(void)
{
	LE = 1;
	LE = 0;
	OE = 0;
}

/*******************************************************************************
* Function Name  : CloseLED(void)
* Description    : 关闭输出
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void CloseLED(void)
{
	OE = 1;
}

void StartLatch(void)
{
	LE = 1;
//	delay_us(1);
	LE = 0;
//	delay_us(1);
}
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
