//! @file
//! This library implements the timer
//! and gives helper functions

//! Initializes the timer
//! 
//! Initializes the timer, needs to be run before other methods
//! can be run
void timer_init( void );

//! Returns the amount of ticks
//!
//! Returns the amount of ticks that happened between startup and now
unsigned int now();

//! Waits until a given moment
//!
//! Waits until a given moment t in microseconds
void await( unsigned int t );

//! Delays the thread
//! 
//! Delays the thread for x ticks
void delay(unsigned int x);


