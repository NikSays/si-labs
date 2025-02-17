#include <Arduino.h>
#include <stdio.h>

#define LED_PIN LED_BUILTIN

void led_setup();

// Second argument will be unused.
int led_putchar(char ch, FILE*); 