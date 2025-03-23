#include "lab.h"

void lab_2_2_task_2(void *pvParameters) {
    while (true) {
        if (!xSemaphoreTake(semaphore, portMAX_DELAY)) {continue;}

        blinks++;
        for (int i = 0; i < blinks; i++) {
            xQueueSend(queue, &i, portMAX_DELAY); 
            vTaskDelay(pdMS_TO_TICKS(50));
        }
  
        for (int i = 0; i < blinks; i++) {
            putc('1', led_2_stream);
            vTaskDelay(pdMS_TO_TICKS(300));
            putc('0', led_2_stream);
            vTaskDelay(pdMS_TO_TICKS(500)); 
        }
    }
}
