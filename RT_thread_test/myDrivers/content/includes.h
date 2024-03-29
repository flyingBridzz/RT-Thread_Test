#ifndef _INCLUDES_H_
#define _INCLUDES_H_


#define					TRUE					1
#define					FALSE					0


#include "main.h"

/* HAL库生成的驱动头文件 start */
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
/* HAL库生成的驱动头文件 end */

/* RT-Thread 相关文件 start */
#include <rtthread.h>
/* RT-Thread 相关文件 end */

/* 自定义的驱动头文件 start */
#include "myUsarthd.h"
#include "myLed.h"
#include "myThread.h"
#include "myKey.h"
/* 自定义的驱动头文件 end */

#endif
