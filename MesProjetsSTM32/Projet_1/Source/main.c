#include "stm32f10x.h"
#include "Driver_GPIO.h"
	
int main (void)
{
	MyGPIO_Struct_TypeDef GPIOC8 = {GPIOC, 8, In_Floating};
	MyGPIO_Struct_TypeDef GPIOC10 = {GPIOC, 10, Out_Ppull};
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ; //allumage des clocks de A B et C
	// GPIOC->CRH |= (0x01 << 9) | (0x01 << 2) | (0x01 << 10) ; // passer le bit 10 à 0 pour revenir en push-pull
	// GPIOC->CRH &= ~((0x01 << 11) | (0x01 << 8) | (0x01 << 0) | (0x01 << 1) | (0x01 << 3)) ;
	MyGPIO_Init(&GPIOC8);
	MyGPIO_Init(&GPIOC10);
	
	do
	{
		/*
		if ((GPIOC->IDR & GPIO_IDR_IDR8) != 0) {
			GPIOC->ODR &= ~(GPIO_ODR_ODR10) ;
		} else {
			GPIOC->ODR |= GPIO_ODR_ODR10 ;
		}
		*/
		if (MyGPIO_Read(GPIOC8.GPIO, 8)) {
			MyGPIO_Set(GPIOC10.GPIO, 10) ;
		} else {
			MyGPIO_Reset(GPIOC10.GPIO, 10) ;
		}
	} while ( 1 ) ;
}
