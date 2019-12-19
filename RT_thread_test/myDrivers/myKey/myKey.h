#ifndef _MY_KEY_H_
#define _MY_KEY_H_

#include "includes.h"

#define		PORT_KEY_UP				GPIOA
#define		PIN_KEY_UP				GPIO_PIN_0

#define		PORT_KEYx					GPIOE
#define		PIN_KEY0					GPIO_PIN_4
#define		PIN_KEY1					GPIO_PIN_3
#define		PIN_KEY2					GPIO_PIN_2

#define		KEY_TGL						TRUE
#define		KEY_NTGL					FALSE

/* 按键检测函数所用参数 */
#define		KEY_UP						(uint8_t)4
#define		KEY0							(uint8_t)0
#define		KEY1							(uint8_t)1
#define		KEY2							(uint8_t)2

extern rt_sem_t KeyUp_Sem;
extern rt_mailbox_t Keyx_Mb;

uint8_t KeyCheck(uint8_t KEYx);

#endif

