#include <avr/io.h>
#include "system.h"
#include "led.h"


int main (void)
{
    system_init ();
    led_init ();
    
    // Initialise timer/counter1
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;
    
    while (1)
    {
        /* Turn LED on.  */
        led_set (LED1, 1);
        
        while (TCNT1 <= 1) {
			continue;
		}
		TCNT1 = 0;
        
        /* Turn LED off.  */
        led_set (LED1, 0);
        
        while (TCNT1 <= 59) {
			continue;
		}
		TCNT1 = 0;
    }
}
