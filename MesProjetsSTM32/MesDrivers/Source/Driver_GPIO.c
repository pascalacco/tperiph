#include <Driver_GPIO.h>

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ){
	RCC->APB2ENR |=(0x01 << 2)|(0x01 << 3)|(0x01 << 4); //init de la clock du GPIO
}
int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	
}
void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ){

}
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	
}
void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	
}

int main (void){
	while(1);
}

// si pin > 7 => taper dans CRH, sinon taper dans CRL
// Dans CRH : GPIO_Conf << ((PIN-7)*4)-1 || Dans CRL : GPIO_Conf  << ((PIN+1)*4)-1

//Read / Set / Reset / Toggle -> modif bit correspondant à la broche (ou read)