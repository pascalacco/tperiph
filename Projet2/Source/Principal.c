#include "stm32f10x.h"
#include "Driver_Timer.h"

#define MYTIMER TIM2
#define MYARR 999
#define MYPSC 35999

MyTimer_Struct_TypeDef  Timer;
int main(void) {
	Timer.Timer = MYTIMER;
	Timer.ARR = MYARR;
	Timer.PSC = MYPSC;

	//RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
	//TIM2->ARR = 35999;
	//TIM2->PSC = 999;
	MyTimer_Base_Init(&Timer);
	MyTimer_Base_Start(&Timer);
	
	while (1){
		
	}
}