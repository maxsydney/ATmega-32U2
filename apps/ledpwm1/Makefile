# File:   Makefile
# Author: M. P. Hayes, UCECE
# Date:   12 Sep 2010
# Descr:  Makefile for ledpwm1

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../drivers/avr -I../../drivers -I../../utils
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: ledpwm1.out


# Compile: create object files from C source files.
ledpwm1.o: ledpwm1.c ../../drivers/avr/system.h ../../drivers/led.h ../../utils/pacer.h ../../utils/spwm.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

led.o: ../../drivers/led.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/led.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

spwm.o: ../../utils/spwm.c ../../drivers/avr/system.h ../../utils/spwm.h
	$(CC) -c $(CFLAGS) $< -o $@




# Link: create output file (executable) from object files.
ledpwm1.out: ledpwm1.o pio.o system.o timer.o led.o pacer.o spwm.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Create hex file for programming from executable file.
ledpwm1.hex: ledpwm1.out
	$(OBJCOPY) -O ihex ledpwm1.out ledpwm1.hex


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: ledpwm1.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash ledpwm1.hex; dfu-programmer atmega32u2 start


