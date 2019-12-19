#include "myKey.h"

uint8_t KeyCheck(uint8_t KEYx)
{
	uint8_t keyState = KEY_NTGL;
	switch(KEYx)
	{
		case KEY0:
			if(HAL_GPIO_ReadPin(PORT_KEYx, PIN_KEY0)==GPIO_PIN_RESET)
			{
				keyState = KEY_TGL;
			}else{
				keyState = KEY_NTGL;
			}
			break;
		case KEY1:
			if(HAL_GPIO_ReadPin(PORT_KEYx, PIN_KEY1)==GPIO_PIN_RESET)
			{
				keyState = KEY_TGL;
			}else{
				keyState = KEY_NTGL;
			}
			break;
		case KEY2:
			if(HAL_GPIO_ReadPin(PORT_KEYx, PIN_KEY2)==GPIO_PIN_RESET)
			{
				keyState = KEY_TGL;
			}else{
				keyState = KEY_NTGL;
			}
			break;
		case KEY_UP:
			if(HAL_GPIO_ReadPin(PORT_KEY_UP, PIN_KEY_UP)==GPIO_PIN_SET)
			{
				keyState = KEY_TGL;
			}else{
				keyState = KEY_NTGL;
			}
			break;
		default:break;
	}
	return keyState;
}

