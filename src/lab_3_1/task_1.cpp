#include "lab.h"

void lab_3_1_task_1(void *pvParameters) {
    TickType_t last_wake_time = xTaskGetTickCount();
    int *sensor_value = (int*) (pvParameters);

    while (true) {
        *sensor_value = analogRead(SENSOR_PIN);
        vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(40));
    }
}