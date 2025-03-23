#include "lab.h"

void lab_2_2_task_3(void *pvParameters) {
    int byte;
    TickType_t last_wake_time = xTaskGetTickCount();

    while (true) {
        if (!xQueueReceive(queue, &byte, portMAX_DELAY)) {continue;}
  
        if (byte == 0) {
            putc('\n', serial_stream);
            fprintf(serial_stream, "Button pressed, blinking: ");
        }
        fprintf(serial_stream, "%d ", byte+1);
        vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(200));
    }
}
