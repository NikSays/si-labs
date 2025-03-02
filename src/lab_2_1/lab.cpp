#include "lab.h"
#define RED_LED_PIN 2
#define GREEN_LED_PIN 3

#define DELAY 50

static FILE *red_led_stream;
static FILE *green_led_stream;
static FILE *serial_stream;
static FILE *numpad_stream;

static int red_led_putchar(char ch, FILE *) {
    return led_putchar(RED_LED_PIN, ch);
}
static int green_led_putchar(char ch, FILE *) {
    return led_putchar(GREEN_LED_PIN, ch);
}

bool t1_last_button_state = false;
bool t1_led_state = false;
int t2_period = 50;
int t2_current = 0;

void lab_2_1_setup() {
    led_setup(RED_LED_PIN);
    led_setup(GREEN_LED_PIN);
    serial_setup();

    // Open streams for STDIO
    red_led_stream = fdevopen(red_led_putchar, NULL);
    green_led_stream = fdevopen(green_led_putchar, NULL);
    serial_stream = fdevopen(serial_putchar, NULL);
    numpad_stream = fdevopen(NULL, numpad_getchar_instant);
}

void lab_2_1_loop() {
    lab_2_1_task_1(green_led_stream, numpad_stream);
    lab_2_1_task_2(red_led_stream);
    lab_2_1_task_3(numpad_stream);
    lab_2_1_task_idle(serial_stream);

    delay(DELAY);
};