//@file This library implements some utility features like min and max

//! Gets the bigger value of two values
//!
//! Returns the bigger value, a or b;
int max(int a, int b);

//! Gets the smaller value of two values
//!
//! Returns the smaller value, a or b;
int min(int a, int b);

//! Converts a number to a char* by filling in 'buffer'
//!
//! Converts a number to a char*. Free() is not needed. Does not work on a value larger than 99
//! due to restraints on the char buffer
void convert_number_to_char(char* buffer, int value);