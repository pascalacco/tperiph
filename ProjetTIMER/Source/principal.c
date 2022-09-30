#include "stm32f10x.h"
#include "MyTimer.h"


MyTimer_Struct_TypeDef Timer2= {TIM2, 999,35999};


int main (void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	MyTimer_Base_Init(&Timer2);
		do
		{ 
		}while(1) ;
}
