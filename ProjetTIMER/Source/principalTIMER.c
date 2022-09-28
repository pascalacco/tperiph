#include "stm32f10x.h"
#include "Driver_GPIO.h"


MyGPIO_Struct_TypeDef GPIOC8 = { GPIOC, 8, In_PullDown};
MyGPIO_Struct_TypeDef GPIOC10 = { GPIOC, 10, Out_Ppull};


int main (void)
{
	
	
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	TIM2->PSC &= ~(0xFFFF<<0);
	TIM2->PSC |= (0x8c9f<<0); // 35999
	TIM2->ARR &= ~(0xFFFF<<0);
	TIM2->ARR |= (0x3e7<<0); //999
	TIM2->TIM2_CR1 |= (0x01<<0);
	
	// initialisation de la fréquence de la clock a 2 Hz au lieur de 72 MHz, prise en compte que la div est faite par PSC+1 et ARR+1 
		do
		{
		}while(1) ;
}
