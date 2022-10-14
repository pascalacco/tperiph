#include <MyTimer.h>

/* callbacks pour les interruptions */
void (*callback1) (void);
void (*callback2) (void);
void (*callback3) (void);
void (*callback4) (void);


void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ){
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
};

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*interrupt) (void)){
	
	if (Timer==TIM1){
		NVIC_EnableIRQ(TIM1_UP_IRQn);
		NVIC_SetPriority(TIM1_UP_IRQn,Prio);
		callback1=interrupt;
	}
	else if (Timer==TIM2){
		NVIC_EnableIRQ(TIM2_IRQn);
		NVIC_SetPriority(TIM2_IRQn,Prio);
		callback2=interrupt;
	}
	else if(Timer==TIM3){
		NVIC_EnableIRQ(TIM3_IRQn);
		NVIC_SetPriority(TIM3_IRQn,Prio);
		callback3=interrupt;
	}
	else if (Timer==TIM4){
		NVIC_EnableIRQ(TIM4_IRQn);
		NVIC_SetPriority(TIM4_IRQn,Prio);
		callback4=interrupt;
	}
}

void TIM1_UP_Handler (void) {
	callback1();
	TIM1->SR &= ~(0x01<<0) ;
}

void TIM2_UP_Handler (void) {
	callback2();
	TIM2->SR &= ~(0x01<<0) ;
}

void TIM3_UP_Handler (void) {
	callback3();
	TIM3->SR &= ~(0x01<<0) ;
}

void TIM4_UP_Handler (void) {
	callback4();
	TIM4->SR &= ~(0x01<<0) ;
}

void MyTimer_PWM(TIM_TypeDef * Timer, char Channel, char RC) {
	if (Channel==1){
		Timer->CCR1 &=~(0xFFFF);
		Timer->CCR1 |=(Timer->ARR/(RC/100));
	}
	else if (Channel==2){
		Timer->CCR2 &=~(0xFFFF);
		Timer->CCR2 |=(Timer->ARR/(RC/100));
	}
	else if (Channel==3){
		Timer->CCR3 &=~(0xFFFF);
		Timer->CCR3 |=(Timer->ARR/(RC/100));
	}
	else{
		Timer->CCR4 &=~(0xFFFF);
		Timer->CCR4 |=(Timer->ARR/(RC/100));
	}
}
