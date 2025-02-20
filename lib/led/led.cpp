#include "led.h"

void led_setup(int led) {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}

int led_putchar(int led, char ch) {
    if(ch == '0') digitalWrite(led, LOW); 
    else digitalWrite(led, HIGH); // Any non-zero char
    return ch;
}
