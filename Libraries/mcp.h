#include "i2c.h"
#include "timer.h"
#include "sw-uart.h"

//Read is one, write is zero
void op(unsigned char rw) ;
void set_all_pullup();

void pol(unsigned char port, unsigned char val);


unsigned char read_register(unsigned char addr) ;


void mcp_pin_as_output(unsigned char port, unsigned char pin);

void mcp_set_pullup(unsigned char port, unsigned char pin, unsigned char val) ;

void mcp_pin_as_input(unsigned char port, unsigned char pin);

void mcp_set_pin(unsigned char port, unsigned char pin, unsigned char s);
unsigned char mcp_get_pin(unsigned char port, unsigned char pin) ;