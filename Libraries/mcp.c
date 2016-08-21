#include "i2c.h"
#include "timer.h"
#include "sw-uart.h"

//Read is one, write is zero
void op(unsigned char rw) {
 i2c_start();
 i2c_put_byte(0x4E + rw);
 i2c_ack_get();
}

void set_all_pullup() {
	op(0);
	i2c_put_byte(0x0D);
	i2c_ack_get();
	i2c_put_byte(0xFF);
	i2c_ack_get();
	i2c_stop();

	op(0);
	i2c_put_byte(0x0C);
	i2c_ack_get();
	i2c_put_byte(0xFF);
	i2c_ack_get();
	i2c_stop();
}

void pol(unsigned char port, unsigned char val) {
	op(0);
	i2c_put_byte(0x2 + port);
	i2c_ack_get();
	i2c_put_byte(val ? 0xFF : 0x00);
	i2c_ack_get();
	i2c_stop();
}


unsigned char read_register(unsigned char addr) {
	op(0);
	i2c_put_byte(addr);
	i2c_ack_get();
	i2c_stop();

	op(1);
	unsigned char x = i2c_get_byte();
	i2c_stop();
	return x;
}


void mcp_pin_as_output(unsigned char port, unsigned char pin) {
	unsigned char current_pins = read_register(port);
	op(0);
	i2c_put_byte(port);
	i2c_ack_get();
	i2c_put_byte(current_pins & (~(1 << pin)));
	i2c_ack_get();
	i2c_stop();

	current_pins = read_register(port);
}


void mcp_set_pullup(unsigned char port, unsigned char pin, unsigned char val) {
	unsigned char current_pins = read_register(0x0C + port);
	op(0);
	i2c_put_byte(0x0C + port);
	i2c_ack_get();
	i2c_put_byte(current_pins | (val << pin));
	i2c_ack_get();
	i2c_stop();
}

void mcp_pin_as_input(unsigned char port, unsigned char pin) {

	unsigned char current_pins = read_register(port);
	mcp_set_pullup(port, pin, 1);

	op(0);
	i2c_put_byte(port);
	i2c_ack_get();
	i2c_put_byte(current_pins | (1 << pin));
	i2c_ack_get();
	i2c_stop(); 
}

void mcp_set_pin(unsigned char port, unsigned char pin, unsigned char s) {
	unsigned char current_pins = read_register(0x12 + port);

	op(0);
	i2c_put_byte(0x12 + port);
	i2c_ack_get();

	if (s) {
		current_pins = current_pins | (1 << pin);
		i2c_put_byte((current_pins));
		}
	else {

		current_pins = current_pins & ~(1 << pin);
		i2c_put_byte(current_pins);
	}

	i2c_ack_get();
	i2c_stop();
	current_pins = read_register(0x12 + port);
}

unsigned char mcp_get_pin(unsigned char port, unsigned char pin) {
	return read_register(0x12 + port) & (1 << pin) ? 1 : 0;
}

void mcp_write_byte(unsigned char address, unsigned char value) {
	op(0);
	i2c_put_byte(address);
	i2c_ack_get();

	i2c_put_byte(value);
	i2c_ack_get();
	i2c_stop();
}
