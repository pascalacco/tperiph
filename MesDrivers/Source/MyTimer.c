#include "MyTimer.h"

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer )
{
	Timer->Timer->CR1 |= (0x01<<0);
	Timer->Timer->ARR &= ~(0xFFFF<<0);
	Timer->Timer->ARR |= (Timer->ARR<<0);
	Timer->Timer->PSC |= ~(0xFFFF<<0);
	Timer->Timer->PSC |= (Timer->PSC<<0);
}