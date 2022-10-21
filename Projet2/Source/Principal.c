#include "stm32f10x.h"
#include "Driver_Timer.h"
#include "Driver_GPIO.h"

#define MYTIMER TIM3
#define MYARR 999
#define MYPSC 35999

MyTimer_Struct_TypeDef  Timer;
MyGPIO_Struct_TypeDef LED;
MyGPIO_Struct_TypeDef Btn;

void callback(void){
		LED.GPIO=GPIOB;
		LED.GPIO_Pin=0;
		LED.GPIO_Conf=Out_Ppull;
		MyGPIO_Init(&LED);
		 MyGPIO_Toggle (  	LED.GPIO ,  	LED.GPIO_Pin );
}
	
		

int main(void) {
	Timer.Timer = MYTIMER;
	Timer.ARR = MYARR;
	Timer.PSC = MYPSC;
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;
	//TIMER INIT
	RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
	//TIM2->ARR = 35999;
	//TIM2->PSC = 999;
	MyTimer_Base_Init(&Timer);
	MyTimer_Base_Start(&Timer);
	
	
		LED.GPIO=GPIOB;
		LED.GPIO_Pin=0;
		LED.GPIO_Conf=Out_Ppull;
		MyGPIO_Init(&LED);
	
	//INTERRUPTION
	MyTimer_ActiveIT(MYTIMER, 5, callback);
	MyTimer_PWM( MYTIMER ,3);
  set_pulse_pwm( MYTIMER ,20);
	
	while (1){
		
		
	}
}
