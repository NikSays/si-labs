#include "lab.h"

void lab_2_2_task_1(void *pvParameters) {
    static char last_button_state = '0';
    char button_state;
    TickType_t last_wake_time = xTaskGetTickCount();
  
    while (true) {
        button_state = getc(button_stream);
        if (button_state == last_button_state) {continue;}

        if (button_state == '1') {
            xSemaphoreGive(semaphore);

            putc('1', led_1_stream);
            vTaskDelay(pdMS_TO_TICKS(1000));
            putc('0', led_1_stream);  
        }

        last_button_state = button_state;
        vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(10));
    }
}