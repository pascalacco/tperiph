#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"
typedef struct
{
GPIO_TypeDef * GPIO ;
char GPIO_Pin ; // numero de 0 a 15
char GPIO_Conf ; // voir cidessous
} MyGPIO_Struct_TypeDef ;
#define In_Floating 0x04 
#define In_PullDown 0x08
#define In_PullUp 0x08
#define In_Analog 0x00
#define Out_Ppull 0x02
#define Out_OD 0x06
#define AltOut_Ppull 0xA
#define AltOut_OD 0xE
void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ) ;
int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ; // r e n v o i e 0 ou a u t r e chose d i f f e r e n t de 0
void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
#endif