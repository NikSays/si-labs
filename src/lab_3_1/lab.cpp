#include "lab.h"

void lab_3_1_setup() {
    serial_setup();
    // vTaskDelay(pdMS_TO_TICKS(1000));
    FILE *serial_stream = fdevopen(serial_putchar, NULL);
    int sensor_value = 123;
    void** params = (void**) malloc(2*sizeof(void*));
    params[0] = (void*) serial_stream;
    params[1] = (void*) &sensor_value;

    // Initialize
    pinMode(SENSOR_PIN, INPUT);

    // Run tasks
    xTaskCreate(lab_3_1_task_1, "Read Sensor", 1024, &sensor_value, 1, NULL);
    xTaskCreate(lab_3_1_task_2, "Print State", 1024, params, 2, NULL);
}