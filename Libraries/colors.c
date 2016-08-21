#include "sw-uart.h"
#include "colors.h"

Color convert_to_color(int red, int green, int blue) {

	//This needs to be done with simple if statements
	//Because the median of those values lies close to all three values
	//So I cant make a accurate decision from them

	if (red < 100 && blue < 100 && green < 100) {
		return WHITE;
	}

	if (blue > 500 && red > 500 && green > 500) {
		return BLACK;
	}

	int median = (red + green + blue)  / 3;

	int red_scaled = median - red;
	int blue_scaled = median - blue;
	int green_scaled = median - green;

	//Now only chooses the three primary colors
	//Other colors can be chosen by combining positive scaled values
	//E.g. if red_scaled is positive and green_scaled is positive
	//but blue_scaled is not: it is yellow, because it mixes
	//The scaled values are a bit like 'redness' and 'blueness', with positive
	//values meaning the color is present

	char color = 0;

	if (red_scaled > blue_scaled && red_scaled > green_scaled) {
		return RED;
	}

	if (blue_scaled > red_scaled && blue_scaled > green_scaled) {
		return BLUE;
	}

	if (green_scaled > blue_scaled && green_scaled > red_scaled) {
		return GREEN;
	}

	return WHITE;

}

Color convert_mixed_colors(int red, int green, int blue) {
	if (red < 100 && blue < 100 && green < 100) {
		return WHITE;
	}

	if (blue > 500 && red > 500 && green > 500) {
		return BLACK;
	}


	int median = (red + green + blue)  / 3;

	int red_scaled = median - red;
	int blue_scaled = median - blue;
	int green_scaled = median - green;

	int result = 0;

	//Convert to RGB in binary format
	result &= red_scaled > 0;
	result = result << 1;
	result &= green_scaled > 0;
	result = result << 1;
	result &= blue_scaled > 0;
	result = result << 1;

	Color colors[8] = {0};
	colors[0] = BLACK;
	colors[1] = BLUE;
	colors[2] = GREEN;
	colors[3] = TURQOISE;
	colors[4] = RED;
	colors[5] = PINK; //More like magenta
	colors[6] = YELLOW;
	colors[7] = WHITE;

	return colors[result];

	
}
	





