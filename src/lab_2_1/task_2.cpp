#include "lab.h"

void lab_2_1_task_2(FILE *led_stream) {
    t2_current = (t2_current + 1) % t2_period;
    if (t2_current * 2 < t2_period) putc('1', led_stream);
    else putc('0', led_stream);
}