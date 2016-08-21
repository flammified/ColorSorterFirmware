#include "flips.h"

void init_flips() {
	pin_configure_as_output(1,4);
	pin_configure_as_output(1,5);
	pin_configure_as_output(1,8);
}


//Bot, Mid, Top
void set_flips(int f, int s, int t) {
	set_one_flip(0,!f);
	set_one_flip(1,!s);
	set_one_flip(2,!t);
}

//0 = Bot
//1 = Mid
//2 = Top
void set_one_flip(int flip, int val) {
	switch(flip) {
		case 0:
			pin_set(1,8,val);
			break;
		case 1:
			pin_set(1,5,val);
			break;
		case 2:
			pin_set(1,4,val);
			break;
	}
}

void set_color_flips(int s, int t) {
	set_one_flip(1, !s);
	set_one_flip(0, !t);
}

	
