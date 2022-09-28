#include "stm32f10x.h"
#include "Driver_GPIO.h"


MyGPIO_Struct_TypeDef GPIOC8 = { GPIOC, 8, In_PullDown};
MyGPIO_Struct_TypeDef GPIOC10 = { GPIOC, 10, Out_Ppull};


int main (void)
{
	
	
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);

	
	MyGPIO_Init(&GPIOC8);
	MyGPIO_Init(&GPIOC10);
	
	//GPIOC->CRH &= ~((0x01<<0) | (0x01<<1)| (0x01<<2) | (0x01<<8) | (0x01<<10) | (0x01<<11)); 
	//GPIOC->CRH |= (0x01<< 3) | (0x01<<9);
		do
		{ 
			if ((MyGPIO_Read(GPIOC, 8)==0)) 
			{
				MyGPIO_Reset(GPIOC, 10);
			}
			else 
			{
				MyGPIO_Set(GPIOC,10);
			}
		}while(1) ;
}
