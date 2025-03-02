#include "numpad.h"

#ifndef NUMPAD
#define NUMPAD
char keymap[ROWS][COLS] = KEYMAP;
byte row_pins[ROWS] = ROW_PINS;
byte col_pins[COLS] = COL_PINS; 
Keypad numpad(makeKeymap(keymap), row_pins, col_pins, ROWS, COLS);
#endif

int numpad_getchar(FILE*){ 
    return numpad.waitForKey();
}