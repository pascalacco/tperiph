#include "MyTimer.h"
#include "stm32f10x.h"

static void (*CallbackTIM1) (void);
static void (*CallbackTIM2) (void);
static void (*CallbackTIM3) (void);
static void (*CallbackTIM4) (void);  

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer )
{
	Timer->Timer->CR1 |= (0x01<<0);
	Timer->Timer->ARR &= ~(0xFFFF<<0);
	Timer->Timer->ARR |= (Timer->ARR<<0);
	Timer->Timer->PSC |= ~(0xFFFF<<0);
	Timer->Timer->PSC |= (Timer->PSC<<0);
}

void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio, void (*IT_function) (void) )
{
	Timer->DIER |= (0x01<<0);
	if (Timer==TIM1)
	{
		NVIC_EnableIRQ(TIM1_UP_IRQn);
		NVIC_SetPriority(TIM1_UP_IRQn, Prio);
		CallbackTIM1=IT_function;
	}
	else if (Timer==TIM2)
	{
		NVIC_EnableIRQ(TIM2_IRQn);
		NVIC_SetPriority(TIM2_IRQn, Prio);
		CallbackTIM2=IT_function;
	}
	else if (Timer==TIM3)
	{
		NVIC_EnableIRQ(TIM3_IRQn);
		NVIC_SetPriority(TIM3_IRQn, Prio);
		CallbackTIM3=IT_function;
	}
	else if (Timer==TIM4)
	{
		NVIC_EnableIRQ(TIM4_IRQn);
		NVIC_SetPriority(TIM4_IRQn, Prio);
		CallbackTIM4=IT_function;
	}
}

void TIM1_UP_IRQHandler (void)
{
	CallbackTIM1();
	TIM1->SR &= ~(0x01<<0);
}

void TIM2_IRQHandler (void)
{
	CallbackTIM2();
	TIM2->SR &= ~(0x01<<0);
}

void TIM3_IRQHandler (void)
{
	CallbackTIM3();
	TIM3->SR &= ~(0x01<<0);
}

void TIM4_IRQHandler (void)
{
	CallbackTIM4();
	TIM4->SR &= ~(0x01<<0);
}

char CCRx_Value(char ARR, char rapCyclique)
{
	return (ARR/(rapCyclique/100));
}

void MyTimer_PWM( TIM_TypeDef * Timer , char Channel, char CCRx ) 
{
	if (Channel==1)
	{
			Timer->CCR1&= ~(0xFFFF<<0);
			Timer->CCR1|= (CCRx<<0);
	}
	else if (Channel==2)
	{
			Timer->CCR2&= ~(0xFFFF<<0);
			Timer->CCR2|= (CCRx<<0);
	}
	else if (Channel==3)
	{
			Timer->CCR3&= ~(0xFFFF<<0);
			Timer->CCR3|= (CCRx<<0);
	}
		else if (Channel==4)
	{
			Timer->CCR4&= ~(0xFFFF<<0);
			Timer->CCR4|= (CCRx<<0);
	}
}