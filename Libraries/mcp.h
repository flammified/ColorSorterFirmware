#include "i2c.h"
#include "timer.h"
#include "sw-uart.h"

//@file This library implements functions for controlling the MCP23017

//! Sends an opcode: read 0, write 1
//!
//! Used internally in the library, used with other commands
void op(unsigned char rw) ;

//! Sets all pins at both ports to pullup
void set_all_pullup();


//! Sets the inverse polarity of a port.
//!
//! Sets the inverse polarity of a port: inverse if val == 1
//! not inverse if val != 1
void pol(unsigned char port, unsigned char val);

//! Reads the register at addr
//!
//! Reads the register at addr and returns it as an unsigned char
unsigned char read_register(unsigned char addr) ;

//! Configures a pin as an output
//!
//! Configures a given pin at a given port as an output
void mcp_pin_as_output(unsigned char port, unsigned char pin);

//! Sets an pin pullup status
//!
//! Sets a pin to pullup if val == 1 and floating if val == 0
void mcp_set_pullup(unsigned char port, unsigned char pin, unsigned char val) ;

//! Configures a pin as an input
//!
//! Configures a given pin at a given port as an input
void mcp_pin_as_input(unsigned char port, unsigned char pin);

//! Sets the output value of a pin
//!
//! Sets the output value of a pin: LOw if s != 1 and HIGH if s == 1
//! The pin must be set as an output first
void mcp_set_pin(unsigned char port, unsigned char pin, unsigned char s);

//! Returns the boolean status of a pin
//!
//! Returns the boolean status of a pin: 1 if HIGH, 0 if LOW
unsigned char mcp_get_pin(unsigned char port, unsigned char pin) ;
