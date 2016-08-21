//@file
//! This library provides an interface to the HD44780 LCD controller using a MCP23017
//! At this moment in time it is write-only
//! The pins are:
//! A0 - A7: D0 - D7
//! B0 - RS
//! B1 - EN(able)
//! Ground - RW


//----------------------------------------------------
//Lower level functions
//----------------------------------------------------

//! Pulses the enable pin to clock in data
//!
//! Pulses the enable pin to clock in data. You must set the data on the pins beforehand
void pulseEnable();

//! Writes a byte using the 4 bit interface
//!
//! Writes a byte val using the 4 bit interface.
//! Charmode indicates wether it is data or an instruction
void write4bitsChar(int val, int charmode);

//! Writes a byte using the 4 bit interface
//!
//! Writes a byte val using the 4 bit interface as an instruction
void write4bits(int val);

//! Initializes the 1602 LCD
//!
//! Initializes the 1602 LCD. Must be run before any other function
void initialize_1602();

//---------------------------------------------------
// Top level functions
//---------------------------------------------------

//! Clears the LCD
//! 
//! Clears the LCD. Takes a long time
void lcd_clear();

//! Makes the cursor of the LCD blink.
//!
//! Makes the cursor of the LCD blink.
void lcd_blink();

//! Makes the cursor of the LCD stop blinking.
//!
//! Makes the cursor of the LCD stop blinking.
void lcd_noblink();

//! Make the cursor of the LCD visible
//!
//! Make the cursor of the LCD visible
void lcd_cursoron();

//! Make the cursor of the LCD no longer visible
//!
//! Make the cursor of the LCD no longer visible
void lcd_cursoron();

//! Sets the cursor at the beginning of the screen
//!
//! Sets the cursor at the beginning of the screen so you can overwrite text
void lcd_home();

//! Turns on the display
//!
//! Turns on the display if it has been turned off
void lcd_on();

//! Turns off the display
//!
//! Turns off the display. Initialization is NOT needed after this.
void lcd_off();

//! Puts the cursor at a position
//!
//! Puts the cursor at a position. Be careful that the position is an address
//! So it is not always a good position number.
//! First row: 	1 		- 	0F
//! Second Row: 0x40 	- 	0x4F 
void lcd_to_position(int position);

//! Puts text on the display
//!
//! Puts text on the display. You can use \n to go to the second line.
void lcd_message(char* text);

