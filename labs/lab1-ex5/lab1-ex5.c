#include "pio.h"
#include "system.h"


int main (void)
{
    system_init ();
    // Initialize columns
    pio_config_set(PC6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB7_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PC4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PC7_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PC5_PIO, PIO_OUTPUT_HIGH);
    
    // Initialize rows
	pio_config_set(PB6_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(PB5_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(PB4_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(PB3_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(PB2_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(PB1_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(PB0_PIO, PIO_OUTPUT_HIGH);
	
    while (1)
    {
		pio_output_low(PC6_PIO);
		pio_output_low(PB7_PIO);
		pio_output_low(PC4_PIO);
		pio_output_low(PC7_PIO);
		pio_output_low(PC5_PIO);
        pio_output_low(PB0_PIO);
    }
}
