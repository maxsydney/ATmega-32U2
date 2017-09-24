#include <avr/io.h>
#include "system.h"

int main (void)
{
    system_init ();
	
	// Initialize LED pin (C2)
    DDRC |= (1<<2);
    
    // Initialize button pin (D7)
    DDRD &= ~(1<<7);

    while (1)
    {
		PORTC &= ~(1<<2);
		
		if (PIND & (1<<7)) {
			
			PORTC |= (1<<2);
			
		}
    }
}
