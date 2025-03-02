#include "lab.h"

void lab_2_1_task_1(FILE *led_stream, FILE *keypad_stream) {
    bool button_state = (getc(keypad_stream) == '1');
    if (button_state && !t1_last_button_state) {
        t1_led_state = !t1_led_state;
        putc((t1_led_state ? '1' : '0'), led_stream);
    }
    t1_last_button_state = button_state;
}