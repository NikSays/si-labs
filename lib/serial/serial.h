#include <Arduino.h>
#include <stdio.h>

#define SERIAL_BAUDRATE 9600

void serial_setup();

// File argument will be unused.
int serial_putchar(char ch, FILE*); 

int serial_getchar(FILE*);
