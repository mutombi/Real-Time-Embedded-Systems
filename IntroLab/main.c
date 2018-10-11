#include "stm32f4xx.h"

int main(void) {
	
	uint32_t ii;
	
	// Initialize GPIO Port for LEDs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable GPIOD clock : could have used 0x00000008
	GPIOD->MODER |= GPIO_MODER_MODER13_0; // GPIOD pin 13 output : could have used 0x03000000
	
	for(;;) {
		
		GPIOD->BSRR = 1<<13; 	// Turn on the orange LED: shifts single bit 12 times to the left
		
		for(ii=0;ii<26000000;ii++){} // FOR loop to implement a 1 second delay using  
		
		GPIOD->BSRR = 1<<(13+16);	// Turn off the orange LED
		
		for(ii=0;ii<26000000;ii++) {}
		
	}
};