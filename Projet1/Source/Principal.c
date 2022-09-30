#include "stm32f10x.h"
#include "./../../MesDrivers/Include/Driver_GPIO.h"
		MyGPIO_Struct_TypeDef LED;
		MyGPIO_Struct_TypeDef Btn;


int main ( void )
{
	
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;

		//PC10  LED
	  LED.GPIO=GPIOC;
		LED.GPIO_Pin=10;
		LED.GPIO_Conf=Out_Ppull;
		MyGPIO_Init(&LED);
	
		//PC8 BP
	  Btn.GPIO=GPIOC;
		Btn.GPIO_Pin=8;
		Btn.GPIO_Conf=In_Floating;
		MyGPIO_Init(&Btn);
	
		while (1)
		{
			if (MyGPIO_Read (GPIOC	 , 8)){
				MyGPIO_Set(GPIOC,10);
			}else{
					MyGPIO_Reset(GPIOC,10);
			}
		}
}
