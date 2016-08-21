#include "bmptk.h"
#include "timer.h"
	
//Setup ADC functionality e.g. power of IOCONFIG block etc.
//Only needs to be run once
//WARNING: YOU NEED TO INIT THE PINS TOO BY USING SET_AS_ADC
int adc_init() {
	LPC_SYSCON->SYSAHBCLKCTRL |=  (1 << 13);
	LPC_SYSCON->SYSAHBCLKCTRL |=  (1 << 16);
	LPC_SYSCON->PDRUNCFG &= ~(1 << 4);
	LPC_ADC->CR |= (0x078 >> 2); //Clock division
}

//One pin at a time
int set_as_adc(int pin) {
	switch (pin) {

		case 0:
		    LPC_IOCON->R_PIO1_0 |=  0x02;
		    LPC_IOCON->R_PIO1_0 &= ~ (1 << 7);
		    LPC_ADC->CR &= ~ 7;
		    LPC_ADC->CR |= (1 << 1); //Pin select
		    break;
		case 1:
		    LPC_IOCON->R_PIO1_1 |=  0x02;
		    LPC_IOCON->R_PIO1_1 &= ~ (1 << 7);
		    LPC_ADC->CR &= ~ 7;
		    LPC_ADC->CR |= (1 << 2); //Pin select
		    break;
		case 2:
		    LPC_IOCON->R_PIO1_2 |=  0x02;
		    LPC_IOCON->R_PIO1_2 &= ~ (1 << 7);
		    LPC_ADC->CR &= ~ 7;
		    LPC_ADC->CR |= (1 << 3); //Pin select
		    break;
	}
}

int adc() {
	//ADC 
    LPC_ADC->CR |= (1 << 24);


    while (LPC_ADC->GDR == (1 << 31)) {
    }
    
    LPC_ADC->CR &=  ~(1 << 24);
    return (LPC_ADC->GDR >> 6) & ~(~0 << (16-6+1));
}
