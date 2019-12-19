#include "myThread.h"

static uint32_t timLen = 10;

void LED0_Thread_Func(void *p_arg)
{
	while(1)
	{
		TOG_LED(0);
		rt_thread_mdelay(500);
	}
}

void LED1_Thread_Func(void *p_arg)
{
	while(1)
	{
		rt_sem_take(KeyUp_Sem, RT_WAITING_FOREVER);
		TOG_LED(1);
	}
}

void UART_Thread_Func(void *p_arg)
{
	while(1)
	{
		rt_sem_take(Uart_Sem, RT_WAITING_FOREVER);
		DealUartData();
	}
}

void KEYUP_Thread_Func(void *p_arg)
{
	while(1)
	{
		if(KeyCheck(KEY_UP) == KEY_TGL)
		{
			rt_thread_mdelay(10);
			if(KeyCheck(KEY_UP) == KEY_TGL)
			{
				rt_sem_release(KeyUp_Sem);
				while(KeyCheck(KEY_UP) == KEY_TGL)
				{
					rt_thread_mdelay(10);
				}
			}
		}
		rt_thread_mdelay(10);
	}
}

void KEYX_Thread_Func(void *p_arg)
{
	rt_mb_send(Keyx_Mb, timLen);
	uint32_t TrigleTimCnt = 0;
	uint8_t  LongTrigleState = 0;
	while(1)
	{
		if(KeyCheck(KEY0) == KEY_TGL)
		{
			rt_thread_mdelay(10);
			if(KeyCheck(KEY0) == KEY_TGL)
			{
				TrigleTimCnt = 0;
				LongTrigleState = 0;
				timLen++;
				rt_mb_send(Keyx_Mb, timLen);
				while(KeyCheck(KEY0) == KEY_TGL)
				{
					rt_thread_mdelay(10);
					if(LongTrigleState < 50)
					{
						LongTrigleState++;
					}
					else
					{
						TrigleTimCnt++;
					}
					if(TrigleTimCnt > 9)
					{
						TrigleTimCnt = 0;
						timLen++;
						rt_mb_send(Keyx_Mb, timLen);
					}
				}
			}
		}
		
		if(KeyCheck(KEY1) == KEY_TGL)
		{
			rt_thread_mdelay(10);
				if(KeyCheck(KEY1) == KEY_TGL)
				{
					TrigleTimCnt = 0;
					LongTrigleState = 0;
					timLen--;
					rt_mb_send(Keyx_Mb, timLen);
					while(KeyCheck(KEY1) == KEY_TGL)
					{
						rt_thread_mdelay(10);
						if(LongTrigleState < 50)
						{
							LongTrigleState++;
						}
						else
						{
							TrigleTimCnt++;
						}
						if(TrigleTimCnt > 9)
						{
							TrigleTimCnt = 0;
							timLen--;
							rt_mb_send(Keyx_Mb, timLen);
						}
					}
				}
		}
		rt_thread_mdelay(10);
	}
}

void Display_Thread_Func(void *p_arg)
{
	uint32_t tmpTimLen = 0;
	rt_base_t Level;
	while(1)
	{
		if(rt_mb_recv(Keyx_Mb, (rt_uint32_t *)&tmpTimLen, 1) == RT_EOK)
		{
			Level = rt_hw_interrupt_disable();
			myPrintf("定时时长 = %d\r\n", tmpTimLen);
			rt_hw_interrupt_enable(Level);
			
		}
		rt_thread_mdelay(10);
	}
}

