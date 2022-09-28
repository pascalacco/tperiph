#include "Driver_GPIO.h"


void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr )
{
	if ((GPIOStructPtr->GPIO_Pin)<8){
		GPIOStructPtr->GPIO->CRL &= ~((0xF<<(GPIOStructPtr->GPIO_Pin)*4));
		GPIOStructPtr->GPIO->CRL |= (((GPIOStructPtr->GPIO_Conf)<<(GPIOStructPtr->GPIO_Pin)*4));
	}
	else {
		GPIOStructPtr->GPIO->CRH &= ~((0xF<<((GPIOStructPtr->GPIO_Pin)-8)*4));
		GPIOStructPtr->GPIO->CRH |= (((GPIOStructPtr->GPIO_Conf)<<((GPIOStructPtr->GPIO_Pin)-8)*4));
	}
}


int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
		switch (GPIO_Pin)
			{
				case 0:
					return (GPIO->IDR & GPIO_IDR_IDR0);
					break;
				case 1:
					return (GPIO->IDR & GPIO_IDR_IDR1);
					break;
				case 2:
					return (GPIO->IDR & GPIO_IDR_IDR2);
					break;
				case 3:
					return (GPIO->IDR & GPIO_IDR_IDR3);
					break;
				case 4:
					return (GPIO->IDR & GPIO_IDR_IDR4);
					break;
				case 5:
					return (GPIO->IDR & GPIO_IDR_IDR5);
					break;
				case 6:
					return (GPIO->IDR & GPIO_IDR_IDR6);
					break;
				case 7:
					return (GPIO->IDR & GPIO_IDR_IDR7);
					break;
				case 8:
					return (GPIO->IDR & GPIO_IDR_IDR8);
					break;
				case 9:
					return (GPIO->IDR & GPIO_IDR_IDR9);
					break;
				case 10:
					return (GPIO->IDR & GPIO_IDR_IDR10);
					break;
				case 11:
					return (GPIO->IDR & GPIO_IDR_IDR11);
					break;
				case 12:
					return (GPIO->IDR & GPIO_IDR_IDR12);
					break;
				case 13:
					return (GPIO->IDR & GPIO_IDR_IDR13);
					break;
				case 14:
					return (GPIO->IDR & GPIO_IDR_IDR14);
					break;
				case 15:
					return (GPIO->IDR & GPIO_IDR_IDR15);
					break;
			}
}

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
			GPIO->ODR|= (0x01<<GPIO_Pin);
}

void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
			GPIO->ODR&= ~(0x01<<GPIO_Pin);
}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
	if (MyGPIO_Read(GPIO, GPIO_Pin))
	{
		GPIO->ODR&= ~(0x01<<GPIO_Pin);
	}
	else
	{
		GPIO->ODR|= (0x01<<GPIO_Pin);
	}
}