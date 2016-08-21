//@file This library implements AD-converter functions

//! Initializes the module
//!
//! Initializes the module. Must be run before
//! using the other functions
int adc_init();

//! Sets the given pin in the range 0-4 to adc
//!
//! Sets the given pin in the range 0-4 to adc.
//! Only one may be the adc pin at the time
int set_as_adc(int pin);

//! Performs an adc conversion
//!
//! Performs an adc conversion on the currently
//! initialized pin
int adc();
