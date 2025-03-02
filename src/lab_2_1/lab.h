#include <stdio.h>
#include "led.h"
#include "serial.h"
#include "numpad.h"

void lab_2_1_setup();
void lab_2_1_loop();

extern bool t1_last_button_state;
extern bool t1_led_state;
extern int t2_period;
extern int t2_current;

void lab_2_1_task_1(FILE *led_stream, FILE *keypad_stream);
void lab_2_1_task_2(FILE *led_stream);
void lab_2_1_task_3(FILE *keypad_stream);
void lab_2_1_task_idle(FILE *serial_stream);