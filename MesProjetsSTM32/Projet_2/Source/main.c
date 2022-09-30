#include "stm32f10x.h"

int main (void) {
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM2->ARR = 5999;
	TIM2->PSC = 5999;
	
	do {
	} while (1) ;
}
