#include "pins.h"

//@file This library implements functions for controlling the servomotors and
//the flips

//! Initializes the pins needed for the flips
//!
//! Initializes the pins needed for the flips. Needs to be run first. 
void init_flips();

//! Sets one flip to a value.
//!
//! Sets a given layer of flips (0, 1 or 2) to a value
//! 2 = top, 1 = middle, 0 = bottom
void set_one_flip(int flip, int val);

//! Sets the lower two layer of flips.
//!
//! Sets the lower two layer of flips. s = middle layer. t = bottom layer
void set_color_flips(int s, int t);