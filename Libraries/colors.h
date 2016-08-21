//@file This library implements functions used to convert RGB values into a color

//The color definitions
typedef enum{RED, GREEN, BLUE, BLACK, WHITE, YELLOW, PINK, TURQOISE} Color;

//! Converts RGB to some color from the Color enum
//!
//! Converts RGB to a color from the Color enum. Only returns WHITE, BLACK and the
//! three primary colors 
Color convert_to_color(int red, int green, int blue);

//! Converts RGB to all color from the Color enum
//!
//! Converts RGB to a color from the Color enum. Can return all colors.
Color convert_mixed_colors(int red, int green, int blue);