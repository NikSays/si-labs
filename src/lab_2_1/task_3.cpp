#include "lab.h"

void lab_2_1_task_3(FILE *keypad_stream) {
    bool down_button_state = (getc(keypad_stream) == '2');
    bool up_button_state = (getc(keypad_stream) == '3');
    if (down_button_state && t2_period > 2) t2_period--;
    if (up_button_state && t2_period < 100) t2_period++;
}