#include "bmptk.h"
#include "adc.h"
#include "pins.h"
#include "flips.h"
#include "colors.h"
#include "timer.h"
#include "sw-uart.h"
#include "1602lcd.h"
#include "util.h"


int main( void ){

    //A bit hardcoded, but a good solution nonetheless
    //The color enum goes from 0-4: 4 colors (black/white is one), 2 sizes
    int count[8] = {0};

    //Positions of the numbers in the display
    int positions[] = {
        1,
        0x41,
        5,
        0x45,
        9,
        0x49,
        13,
        0x4D
    };

    timer_init();
    uart_init();

    initialize_1602();
    lcd_cursoroff();

    adc_init();
    set_as_adc(0);

    init_flips();
    set_flips(0,0,0);

    pin_configure_as_input(1,3);
    pin_configure_as_input(0, 6);
    pin_configure_as_input(0, 7);

    int r;
    int g;
    int b;
    int i;
    int running = 1;
    int big = 0;

    lcd_clear();
    lcd_message("R00 G00 B00 O00S\nR00 G00 B00 O00B");

    while (running)  {

        //While no bead goes past
        while (!pin_get(1,3)) {}  
        set_one_flip(2, 0); 

        //Initialize the values for the new bead
        r = 10000;
        g = 10000;
        b = 10000;
        big = 0;
        int bigSeen = 0;
        int n = now();

        //Until the last sensor sees the beads OR the timeout is there
        //to stop it from running forever
        while (!pin_get(0,6) && ((now() - n) < (500 * 1000)))  {

            //Get the lowest value for all sensors
            int t;
            set_as_adc(0);
            t = adc();

            b = min(t, b);

            set_as_adc(1);
            t = adc();
            g = min(g, t);

            set_as_adc(2);
            t = adc();
            r = min(t, r);


            //And check if the higher placed sensor is triggered once
            //bigSeen = pin_get(0,7);
            if (pin_get(0,7)) {

                //If so: set the first flip accordingly
                big = 1;
                set_one_flip(2, 1);
            }
        }

        //And convert it to a color!
        //Magic is happening here
        Color c = convert_to_color(r, g, b);
        switch (c) {

            case RED:
                set_color_flips(0,1);
                break;

            case BLACK:
                set_color_flips(0,0);
                break;

            //Green: 010
            case GREEN:
                set_color_flips(1,0);
                break;

            case BLUE:
                set_color_flips(1,1);
                break;

            case WHITE:
                set_color_flips(0,0);
                break;

             default:
                set_color_flips(0,0);
                break;
        }
        //max filters black and white, because they lie next to each other
        count[min(c * 2, 6) + big]++;
        lcd_to_position(positions[min(c * 2, 6) + big]);

        //Its 3 in length for the zero terminator. Without it, it will print a
        //bit of the memory next to it as well
        //Lesson learned I guess
        char buffer[3] = {0};
        convert_number_to_char(buffer, count[min(c * 2, 6) + big]);
        lcd_message(buffer);
    }
}