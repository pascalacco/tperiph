#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"


MyTimer_Struct_TypeDef Timer2= {TIM2, 99,719};
MyGPIO_Struct_TypeDef GPIOC10 = { GPIOC, 10, Out_Ppull};

void CallBackTim (void)
{
	MyGPIO_Toggle(GPIOC, 10);
}

int main (void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	MyGPIO_Init(&GPIOC10);
	MyTimer_Base_Init(&Timer2);
	MyTimer_ActiveIT(TIM2, 1, CallBackTim);
	MyTimer_PWM(TIM2, 2, CCRx_Value(9,20));
	
		do
		{ 
		}while(1) ;
}
