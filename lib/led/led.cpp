#include "led.h"

void led_setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

int led_putchar(char ch, FILE* _) {
    if(ch == '0') digitalWrite(LED_PIN, LOW); 
    else digitalWrite(LED_PIN, HIGH); // Any non-zero char
    return ch;
}
