#include <avr/io.h>
#include "timer.h"

/* Initialise timer.  */
void timer_init (void)
{
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;
}


/* Wait for the specified length of time.  */
void timer_delay_ms (uint16_t milliseconds)
{	
	TCNT1 = 0;
    uint16_t delay = milliseconds/0.128;
    while (TCNT1 <= delay) {
		continue;
	}
}
