#include "stm32f10x.h"
#include <MyTimer.h>

int main (void) {
	MyTimer_Struct_TypeDef Timer2 = {TIM2, 5999, 5999};
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
	MyTimer_Base_Init(&Timer2);
	MyTimer_Base_Start(&Timer2);
	MyTimer_PWM(TIM2,20,1);
		
	do {
	} while (1) ;
}
