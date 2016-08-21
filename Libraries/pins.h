//! @file
//! This library gives the user functions
//! that control the GPIO pins and
//! peripherals that are attached


//! Configures a pin as input
//!
//! This function configures a pin as an input
//! @param port The port of the pin
//! @param pin The pin number of the pin
void pin_configure_as_input(int port, int pin);

//! Configures a pin as an output
//!
//! This function configures a pin as output
//! Needs to be executed if you want to use pin_set
//! @param port The port of the pin
//! @param pin The pin number of the pin
void pin_configure_as_output(int port, int pin);

//! Sets a port to a value
//! 
//! Sets the given pin with the given port to the given value
//! @param port The port of the pin
//! @param pin The pin number
//! @param x The state the pin needs to be: 1 or 0
void pin_set(int port, int pin, unsigned char x);

//! Returns the state of the given pin
//!
//! Returns 1 or 0, corresponding with the state of the pin
unsigned char pin_get(int port, int pin);

//! Initializes a servo
//! 
//! Initializes a servo connected to a pin
//! Needs to be run before other commands can be executed
//! @param port The port of the pin
//! @param pin The pin number
void servo_init(int port, int pin);

//! Moves a servo to a position
//! 
//! Sends the signals neccesary for moving a servo motor to a position to a pin
//! @param port The port of the pin the servo is connected to
//! @param pin The pin number the servo is connected to
//! @param position The position the servo needs to go to expressed in a number
void servo_pulse(int port, int pin, int position);

//! Performs an AD-conversion on pin 0 of port 1 and returns the result
//!
//! Performs an AD-conversion on pin 0 of port 1. Waits for the result and then returns it. 
int adc();
