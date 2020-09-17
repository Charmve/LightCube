/**
  ******************************************************************************
  * @file    TFCard.c
  * $Author: SFZ $
  * $Revision: 1 $
  * $Date:: 2018-11-27 16:16:48 +0800 #$
  * @brief   内存卡读取函数.
  ******************************************************************************
  * @attention
  *
  * 
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "TFCard.h"

/* Private define ------------------------------------------------------------*/
//const char* Filename1 = "0:test.txt";

/* Private variables ---------------------------------------------------------*/
	FATFS fs;			//Fatfs文件系统对象
	FIL fnew;			//文件对象
	UINT fnum;			//文件成功读写的数量
	FRESULT res_flash;	//
	BYTE buffer[ReadFileNum]={0};		//读缓存区
	unsigned char Face[4][5184]={0};

/*******************************************************************************
* Function Name  : TFCard_Init()
* Description    : 挂载文件系统
* Input          : - data:
* Output         : 失败时串口输出mount filesystem failed : %d\n\r",res_flash
* Return         : None
* Attention		   : None
*******************************************************************************/
void TFCard_Init()
{
	//挂载文件系统
	res_flash = f_mount(0,&fs);
}

/*******************************************************************************
* Function Name  : TFCard_Deinit()
* Description    : 取消挂载文件系统
* Input          : - data:
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void TFCard_Deinit()
{
	f_mount(NULL,&fs);	//取消文件系统的挂载
}

/*******************************************************************************
* Function Name  : OpenFile(const char* FileName)
* Description    : 打开文件
* Input          : const char* FileName
* Output         : 读取的文件数据存放在buffer数组中，每次读取ReadFileNum位
* Return         : None
* Attention		   : None
*******************************************************************************/
void OpenFile(const char* Filename)
{
	f_open(&fnew,Filename,FA_OPEN_EXISTING | FA_READ);
}

/*******************************************************************************
* Function Name  : ReadFile(const char* FileName)
* Description    : 读取指定文件名中的数据
* Input          : void
* Output         : 读取的文件数据存放在buffer数组中，每次读取ReadFileNum位
* Return         : None
* Attention		   : None
*******************************************************************************/
void ReadFile(void)
{
	f_read(&fnew,buffer,ReadFileNum,&fnum);
//	int i=0;
//	for(;i<10368;i++)
//		printf("%c",buffer[i]);
//		convert();
}
/*******************************************************************************
* Function Name  : CloseFile()
* Description    : 关闭当前打开的文件
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void CloseFile()
{
	f_close(&fnew);
}

/*******************************************************************************
* Function Name  : convert(void)
* Description    : 将内存卡读出的数据转换为PWM数据等待写入
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
int convert(void)
{
	int i=0;
  static int t=0;	
	unsigned char temp;
	for(i=0;i<10368;i++)
	{
		if(buffer[i] <= 57) buffer[i]-=48; //0~9的数字
		else buffer[i] -= 55;  //a~f 字母
	}
	for(i=0;i<10368;i+=2)
	{
		if(buffer[i]==15 && buffer[i+1]==15) {Face[0][t]=1;Face[1][t]=1;Face[2][t]=1;Face[3][t]=1;}
		else if(buffer[i]==0&&buffer[i+1]==0) {Face[0][t]=0;Face[1][t]=0;Face[2][t]=0;Face[3][t]=0;}
		else if(buffer[i]<4){Face[0][t]=1;Face[1][t]=0;Face[2][t]=0;Face[3][t]=0;}
		else if(buffer[i]<8){Face[0][t]=1;Face[1][t]=1;Face[2][t]=0;Face[3][t]=0;}
		else if(buffer[i]<13){Face[0][t]=1;Face[1][t]=1;Face[2][t]=1;Face[3][t]=0;}
		else {Face[0][t]=1;Face[1][t]=1;Face[2][t]=1;Face[3][t]=1;}
		t++;
		
		if(t == 5184) 
		{
			for(t=0;t<5184;t+=3)
			{
				temp=Face[0][t];
				Face[0][t]=Face[0][t+1];
				Face[0][t+1]=Face[0][t+2];
				Face[0][t+2]=temp;
				
				temp=Face[1][t];
				Face[1][t]=Face[1][t+1];
				Face[1][t+1]=Face[1][t+2];
				Face[1][t+2]=temp;
				
				temp=Face[2][t];
				Face[2][t]=Face[2][t+1];
				Face[2][t+1]=Face[2][t+2];
				Face[2][t+2]=temp;
				
				temp=Face[3][t];
				Face[3][t]=Face[3][t+1];
				Face[3][t+1]=Face[3][t+2];
				Face[3][t+2]=temp;
//				
//				temp=Face[4][t];
//				Face[4][t]=Face[4][t+1];
//				Face[4][t+1]=Face[4][t+2];
//				Face[4][t+2]=temp;
//				
//				temp=Face[5][t];
//				Face[5][t]=Face[5][t+1];
//				Face[5][t+1]=Face[5][t+2];
//				Face[5][t+2]=temp;
//				
//				temp=Face[6][t];
//				Face[6][t]=Face[6][t+1];
//				Face[6][t+1]=Face[6][t+2];
//				Face[6][t+2]=temp;
//				
//				temp=Face[7][t];
//				Face[7][t]=Face[7][t+1];
//				Face[7][t+1]=Face[7][t+2];
//				Face[7][t+2]=temp;
			}
			t=0;
		}
	}
	return 0;
}
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
