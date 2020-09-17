#ifndef	__LED_CUBE_H
#define __LED_CUBE_H
/* Includes ------------------------------------------------------------------*/
#include "sys.h"
#include "SM12126.h"
#include "TFCard.h"
#include "ff.h"
#include "diskio.h"
#include "integer.h"
#include "ffconf.h"
#include "SPI_MSD0_Driver.h"

/* Private define ------------------------------------------------------------*/
//读缓存区大小定义
#define A0 PCout(11)
#define A1 PDout(0)
#define A2 PCout(10)
#define A3 PCout(12)

/* Private variables ---------------------------------------------------------*/
extern int NONE_flag;
extern int ALL_flag;
extern int MAGIC_flag;
extern int JJ_flag;
//extern const unsigned short RGB_All_Light[];

/* Private function prototypes -----------------------------------------------*/
void Level_GPIO_Init(void);
void SelectLevel(unsigned char level);
void FreshLevel(void);

//One Totem
void ShowOneTotem(void);

//static
void ShowALL(void);
void ShowNONE(void);
void ShowMAGIC(void);
void ShowJJ(void);
//moving
void ShowFPGA(void);
void ShowCUBE(void);
void ShowSPIRAL(void);
void ShowSWIRLS(void);
void ShowRIPPLE(void);
void ShowIMP(void);
void ShowSIN(void);
void ShowCOUNT(void);


#endif
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
