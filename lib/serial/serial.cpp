#include "serial.h"

void serial_setup(){
    Serial.begin(SERIAL_BAUDRATE);
};

int serial_putchar(char ch, FILE* _) {
    Serial.write(ch);
    return ch;
}; 

int serial_getchar(FILE* _) {
    while(!Serial.available());
    return Serial.read();
};