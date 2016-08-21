#include "timer.h"
#include "pins.h"
#include "bmptk.h"
#include "sw-uart.h"

void pin_configure_as_input(int port, int pin) {
	if (port == 0) {
		LPC_GPIO0->DIR = LPC_GPIO0->DIR & ~ ( 1 << pin );
	}
	else {
		LPC_GPIO1->DIR = LPC_GPIO1->DIR & ~ ( 1 << pin );
	}
}

void pin_configure_as_output(int port, int pin) {
	if (port == 0) {
		LPC_GPIO0->DIR = LPC_GPIO0->DIR | ( 1 << pin );
	}
	else {
		LPC_GPIO1->DIR = LPC_GPIO1->DIR | ( 1 << pin );
	}
}

void pin_set(int port, int pin, unsigned char x) {
	if (port == 0) {
		if (x) {
			LPC_GPIO0->DATA = LPC_GPIO0->DATA | ( 1 << pin);		
		}
		else {
			LPC_GPIO0->DATA = LPC_GPIO0->DATA & ~ ( 1 << pin);		
		}
		
	}
	else {
		if (x) {
			LPC_GPIO1->DATA = LPC_GPIO1->DATA | ( 1 << pin);		
		}
		else {
			LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ ( 1 << pin);		
		}
	}
}

unsigned char pin_get(int port, int pin) {
	if (port == 0) {
		return (LPC_GPIO0->DATA & ( 1 << pin)) ? 1 : 0;		
	}
	else {
		return (LPC_GPIO1->DATA & ( 1 << pin)) ? 1 : 0;
	}
}

void servo_init(int port, int pin) {
	pin_configure_as_output(port, pin);
	pin_set(port, pin, 0);
}

void servo_pulse(int port, int pin, int position) {
	pin_set(port, pin, 1);
	delay(position);
	pin_set(port, pin, 0);
}
