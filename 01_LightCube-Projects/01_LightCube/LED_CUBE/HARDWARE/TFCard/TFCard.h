#ifndef __TFCARD_H
#define __TFCARD_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "delay.h"
#include "sys.h"
#include "ff.h"
#include "usart.h"
#include "diskio.h"
#include "integer.h"
#include "ffconf.h"
#include "SPI_MSD0_Driver.h"
#include "SM12126.h"

/* Private define ------------------------------------------------------------*/
//读缓存区大小定义
#define ReadFileNum 10368

/* Private variables ---------------------------------------------------------*/
extern	FATFS fs;			//Fatfs文件系统对象
extern	FIL fnew;			//文件对象
extern	UINT fnum;			//文件成功读写的数量
extern	BYTE buffer[ReadFileNum];		//读缓存区
extern unsigned char Face[4][5184];	//3*12*12*3

/* Private function prototypes -----------------------------------------------*/
void TFCard_Init(void);
void TFCard_Deinit(void);
void OpenFile(const char* Filename);
void ReadFile(void);
void CloseFile(void);
int convert(void);
#endif 

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
