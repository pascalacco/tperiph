#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"


MyTimer_Struct_TypeDef Timer1= {TIM1, 999,35999};
MyGPIO_Struct_TypeDef GPIOC10 = { GPIOC, 10, Out_Ppull};

void CallBackTim (void)
{
	MyGPIO_Toggle(GPIOC, 10);
}

int main (void)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	MyGPIO_Init(&GPIOC10);
	MyTimer_Base_Init(&Timer1);
	MyTimer_ActiveIT(TIM1, 1, CallBackTim);
	
		do
		{ 
		}while(1) ;
}
