#ifndef _INCLUDES_H_
#define _INCLUDES_H_


#define					TRUE					1
#define					FALSE					0


#include "main.h"

/* HAL�����ɵ�����ͷ�ļ� start */
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
/* HAL�����ɵ�����ͷ�ļ� end */

/* RT-Thread ����ļ� start */
#include <rtthread.h>
/* RT-Thread ����ļ� end */

/* �Զ��������ͷ�ļ� start */
#include "myUsarthd.h"
#include "myLed.h"
#include "myThread.h"
#include "myKey.h"
/* �Զ��������ͷ�ļ� end */

#endif
