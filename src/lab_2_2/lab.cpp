#include "lab.h"

SemaphoreHandle_t semaphore; 
QueueHandle_t queue;

FILE *led_1_stream;
FILE *led_2_stream;
FILE *serial_stream;
FILE *button_stream;

volatile int blinks = 0;

static int led_1_putchar(char ch, FILE *) {
    return led_putchar(LED1_PIN, ch);
}
static int led_2_putchar(char ch, FILE *) {
    return led_putchar(LED2_PIN, ch);
}
static int blink_button_getchar(FILE *) {
    return button_getchar(BUTTON_PIN);
}

void lab_2_2_setup() {
    led_setup(LED1_PIN);
    led_setup(LED2_PIN);
    button_setup(BUTTON_PIN);
    serial_setup();

    led_1_stream = fdevopen(led_1_putchar, NULL);
    led_2_stream = fdevopen(led_2_putchar, NULL);
    serial_stream = fdevopen(serial_putchar, NULL);
    button_stream = fdevopen(NULL, blink_button_getchar);
  
    // Initialize
    semaphore = xSemaphoreCreateBinary();
    queue = xQueueCreate(10, sizeof(int)); 
    blinks = 0;

    // Run tasks
    xTaskCreate(lab_2_2_task_1, "Button LED Task", 1024, NULL, 1, NULL);
    xTaskCreate(lab_2_2_task_2, "Sync Task", 1024, NULL, 2, NULL);
    xTaskCreate(lab_2_2_task_3, "Async Task", 1024, NULL, 3, NULL);
}