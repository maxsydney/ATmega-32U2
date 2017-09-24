#include "system.h"
#include "pio.h"

/* Include the pacer module from the previous lab.
   You must have completed this before starting this lab2-exercise.  */
#include "pacer.h"

int main (void)
{
    system_init ();
    
    /* TODO: Initialise the pins of the LED matrix.  */
    pio_config_set (PC6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (PC5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (PB6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (PB0_PIO, PIO_OUTPUT_HIGH);
    

    /* Set up pacer with a frequency of 50 Hz.  */
    pacer_init (50);

    while (1)
    {
        /* Pace the loop.  */
        pacer_wait ();
        
        // Drive LED matrix
        pio_output_low(PC6_PIO);
        pio_output_low(PB6_PIO);
        pio_output_low(PB0_PIO);
        
    }
}
