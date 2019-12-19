#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

#include "includes.h"

void LED0_Thread_Func(void *p_arg);
void LED1_Thread_Func(void *p_arg);
void UART_Thread_Func(void *p_arg);
void KEYUP_Thread_Func(void *p_arg);
void KEYX_Thread_Func(void *p_arg);
void Display_Thread_Func(void *p_arg);

#endif
