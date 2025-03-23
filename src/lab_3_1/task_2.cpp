#include "lab.h"

void lab_3_1_task_2(void *pvParameters) {
    vTaskDelay(pdMS_TO_TICKS(1000));

    TickType_t last_wake_time = xTaskGetTickCount();
    FILE *serial_stream = (FILE*) ((void**)pvParameters)[0];
    int *sensor_value = (int*) ((void**)pvParameters)[1];
    while (true) {
        fprintf(serial_stream, "Read value: %d\n", *sensor_value);
        vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(500));
    }
}
