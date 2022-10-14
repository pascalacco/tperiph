#include "Driver_Timer.h"



void MyTimer_Base_Init( MyTimer_Struct_TypeDef * Timer ){
	
	if (Timer->Timer == TIM1){
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
	}else if (Timer->Timer == TIM2) {
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
	}else if (Timer->Timer == TIM13) {
		RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
	}else if (Timer->Timer == TIM4) {
		RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
	
}

void TIM1_CC_IRQHandler (void){
	TIM1->SR |= TIM_SR_UIF;
}

void TIM2_IRQHandler (void) {
	TIM2->SR &= ~(TIM_SR_UIF) ;
}

void TIM3_IRQHandler (void) {
	TIM3->SR |= TIM_SR_UIF;
}

void TIM4_IRQHandler (void) {
	TIM4->SR |= TIM_SR_UIF;
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer, uint32_t Prio){
	
	Timer->DIER |= TIM_DIER_UIE;
	
	if (Timer == TIM1){
			NVIC_EnableIRQ(TIM1_UP_IRQn);
			NVIC_SetPriority(TIM1_UP_IRQn, Prio);
		TIM1_CC_IRQHandler();
	}
	else	if (Timer == TIM2){
			NVIC_EnableIRQ(TIM2_IRQn);
			NVIC_SetPriority(TIM2_IRQn, Prio);
			TIM2_IRQHandler();
	}
	else if (Timer == TIM3){
		NVIC_EnableIRQ(TIM3_IRQn);
		NVIC_SetPriority(TIM3_IRQn, Prio);
		TIM3_IRQHandler();
	}
	else if (Timer == TIM4){
		NVIC_EnableIRQ(TIM4_IRQn);
		NVIC_SetPriority(TIM4_IRQn, Prio);
		TIM4_IRQHandler();
	}
}
