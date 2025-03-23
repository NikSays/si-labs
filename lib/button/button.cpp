#include "button.h"

void button_setup(int button) {
    pinMode(button, INPUT);
}

int button_getchar(int button) {
    return digitalRead(button) ? '1' : '0';
}
