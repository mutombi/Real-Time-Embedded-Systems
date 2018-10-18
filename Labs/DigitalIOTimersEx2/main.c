#include "stm32f4xx.h"

int main(void) {

	// Initialisation for LED
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;		// Enable GPIOD clock
	GPIOD->MODER |= GPIO_MODER_MODER12_0;		// set GPIOD pin 12 to be output (for green LED)
	
	// Initalisation for Pushbutton
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		// enable GPIOA clock
	GPIOA->MODER |= ~GPIO_MODER_MODER0; 			/* set pin 0 on port A (blue push button) to an input state
	and is the putting bit 00 so it's an input? :check this*/
	
	for(;;) {
		if((GPIOA->IDR & 0x00000001) == 0x00000001)
			GPIOD->BSRR = 1<<12;			
		else
			GPIOD->BSRR = 1<<(12+16);
	}

}