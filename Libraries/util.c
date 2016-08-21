#include "util.h"

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

char convert_single_to_char(int value) {
	switch (value) {
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
	}
}

void convert_number_to_char(char* buffer, int value) {
	if (value >= 10) {
		buffer[0] = convert_single_to_char(value / 10);
		value -= (value / 10) * 10;
	}
	else {
		buffer[0] = '0';
	}
	buffer[1] = convert_single_to_char(value);
}

