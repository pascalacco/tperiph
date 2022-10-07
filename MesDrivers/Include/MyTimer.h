
#ifndef MYTIMER_H
#define  MYTIMER_H
#include "stm32f10x.h"
typedef struct
{
TIM_TypeDef * Timer ; // TIM1 à TIM4
unsigned short ARR ;
unsigned short PSC ;
} MyTimer_Struct_TypeDef ;
/*
*****************************************************************************************
* @brief
* @param -> Paramè t r e sous forme d ’ une s t r u c t u r e ( son a d r e s s e ) c o n t e n a n t l e s
i n f o r m a t i o n s de base
* @Note -> F o n c t i o n à l a n c e r s y s t é matiquement avant d ’ a l l e r p l u s en dé t a i l dans l e s
c o n f p l u s f i n e s (PWM, codeur i n c . . . )
*************************************************************************************************
*/
void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;
void MyTimer_ActiveIT (  TIM_TypeDef * Timer , char Prio, void (*IT_function) (void) ) ;
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) ;
#define MyTimer_Base_Start ( Timer ) ( . . . )
#define MyTimer_Base_Stop ( Timer ) ( . . . )
#endif

