#include "stm32f4xx.h"

int main(void) {
	
	uint32_t ii;
	
	// Initialize GPIO Port for LEDs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable GPIOD clock
	GPIOD->MODER |= GPIO_MODER_MODER12_0; // GPIOD pin 12 output
	
	for(;;) {
		
		GPIOD->BSRR = 1<<12; 	// Turn on the green LED: shifts single bit 12 times to the left
		
		for(ii=0;ii<26000000;ii++){} // FOR loop to implement a 1 second delay using  
		
		GPIOD->BSRR = 1<<(12+16);	// Turn off the green LED
		
		for(ii=0;ii<26000000;ii++) {}
		
	}
};