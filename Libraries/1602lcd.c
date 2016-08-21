#include "timer.h"
#include "1602lcd.h"
#include "mcp.h"


#define RS 0
//Not connected
//#define RW 6
#define EN 1



//commands
#define LCD_CLEARDISPLAY 		0x01
#define LCD_RETURNHOME          0x02
#define LCD_ENTRYMODESET        0x04
#define LCD_DISPLAYCONTROL      0x08
#define LCD_CURSORSHIFT         0x10
#define LCD_FUNCTIONSET         0x20
#define LCD_SETCGRAMADDR        0x40
#define LCD_SETDDRAMADDR        0x80

//flags for display entry mode
#define LCD_ENTRYRIGHT          0x00
#define LCD_ENTRYLEFT           0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

//lags for display on/off control
#define LCD_DISPLAYON           0x04
#define LCD_DISPLAYOFF          0x00
#define LCD_CURSORON            0x02
#define LCD_CURSOROFF           0x00
#define LCD_BLINKON             0x01
#define LCD_BLINKOFF            0x00

//flags for display/cursor shift
#define LCD_DISPLAYMOVE         0x08
#define LCD_CURSORMOVE          0x00

//flags for display/cursor shift
#define LCD_DISPLAYMOVE    		0x08
#define LCD_CURSORMOVE          0x00
#define LCD_MOVERIGHT           0x04
#define LCD_MOVELEFT            0x00

//flags for function set
#define LCD_8BITMODE            0x10
#define LCD_4BITMODE            0x00
#define LCD_2LINE               0x08
#define LCD_1LINE               0x00
#define LCD_5x10DOTS            0x04
#define LCD_5x8DOTS             0x00

int displaycontrol;
int displayfunction;
int displaymode;

void pulseEnable() {
	//uart_put_string("Pulsing enable\n");
	delay(1);
	mcp_set_pin(1, EN, 0);
	delay(1);
	mcp_set_pin(1, EN, 1);
	delay(1);
	mcp_set_pin(1, EN, 0);
}

void write4bitsChar(int val, int charmode) {

	delay(1000);
	mcp_set_pin(1, RS, charmode);
	int i = 0;

	for (i = 8; i > 4; i--) {
		//uart_put_int_decimal((val & ( 1 << (i - 1) )) >> (i - 1));
		mcp_set_pin(0, i-1, (val & ( 1 << (i - 1) )) >> (i - 1));
	}

	//uart_put_string("\n");
	pulseEnable();

	for (i = 4; i > 0; i--) {
		//uart_put_int_decimal((val & ( 1 << (i - 1) )) >> (i - 1));
		mcp_set_pin(0, i+3, (val & ( 1 << (i - 1) )) >> (i - 1));
	}

	//uart_put_string("\n");
	pulseEnable();
}

void write4bits(int val) {
	write4bitsChar(val, 0);
}

void lcd_clear() {
	write4bits(LCD_CLEARDISPLAY);
	delay(6000);
}

void lcd_blink() {
	displaycontrol |= LCD_BLINKON;
	write4bits(LCD_DISPLAYCONTROL | displaycontrol);
}

void lcd_noblink() {
	displaycontrol &= ~LCD_BLINKON;
	write4bits(LCD_DISPLAYCONTROL | displaycontrol);
}

void lcd_cursoron() {
	displaycontrol |= LCD_CURSORON;
	write4bits(LCD_DISPLAYCONTROL | displaycontrol);
}

void lcd_cursoroff() {
	displaycontrol &= ~LCD_CURSORON;
	write4bits(LCD_DISPLAYCONTROL | displaycontrol);
}



void initialize_1602() {
	delay(1);
	uart_put_string("Initializing\n");
	//mcp_pin_as_output(0, RW); NOT CONNECTED
	mcp_pin_as_output(1, RS);
	mcp_pin_as_output(1, EN);

	mcp_set_pin(1, RS, 0);
	mcp_set_pin(1, EN, 0);
	int i;

	for (i = 0; i < 8; i++) {
		mcp_pin_as_output(0, i);
		mcp_set_pin(0, i, 0);
	}

	write4bits(0x33);
	write4bits(0x32);
	write4bits(0x28);
	write4bits(0x0E);
	write4bits(0x06);

	displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
	displayfunction |= LCD_2LINE;
	displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;

	write4bits(LCD_ENTRYMODESET | displaymode);

	lcd_clear();
}

void lcd_home() {
	write4bits(LCD_RETURNHOME);
	delay(3000);
}

void lcd_on() {
	displaycontrol |= LCD_DISPLAYON;
	write4bits(LCD_DISPLAYCONTROL | displaycontrol);
}

void lcd_off() {
	displaycontrol &= ~LCD_DISPLAYON;
	write4bits(LCD_DISPLAYCONTROL | displaycontrol);
}

void lcd_to_position(int position) {
	write4bits(LCD_SETDDRAMADDR + position);
}

void lcd_message(char* text) {
	int i = 0;

	for (i = 0; text[i] != 0; i++){
		//uart_put_char(text[i]);
		if (text[i] == '\n') {
			write4bits(0xC0);
		}
		else {
			//uart_put_int_decimal(text[i]);
			write4bitsChar(text[i], 1);
		}
	}
}
