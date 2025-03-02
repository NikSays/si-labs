#include "lab.h"

void lab_2_1_task_idle(FILE *serial_stream) {
    fprintf(serial_stream, "T1 button state: %i; ", t1_last_button_state);
    fprintf(serial_stream, "T1 LED state: %i; ", t1_led_state);
    fprintf(serial_stream, "T2: %i/%i; ", t2_current, t2_period);
    fprintf(serial_stream, "\n");
}