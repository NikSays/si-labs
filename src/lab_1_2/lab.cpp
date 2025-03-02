#include "lab.h"
#define RED_LED_PIN 2
#define GREEN_LED_PIN 3

#define PASSWORD "1337"

static FILE *red_led_stream;
static FILE *green_led_stream;
static FILE *lcd_stream;
static FILE *keypad_stream;

static int red_led_putchar(char ch, FILE *) {
    return led_putchar(RED_LED_PIN, ch);
}
static int green_led_putchar(char ch, FILE *) {
    return led_putchar(GREEN_LED_PIN, ch);
}

void lab_1_2_setup() {
    led_setup(RED_LED_PIN);
    led_setup(GREEN_LED_PIN);
    lcd_setup();

    // Open streams for STDIO
    red_led_stream = fdevopen(red_led_putchar, NULL);
    green_led_stream = fdevopen(green_led_putchar, NULL);
    lcd_stream = fdevopen(lcd_putchar, NULL);
    keypad_stream = fdevopen(NULL, numpad_getchar);
}

void lab_1_2_loop() {
    fprintf(lcd_stream, "Enter code: ");

    // initialize with 0 so the string is always null-terminated
    char pass[5] = {0};

    for (int i = 0; i < 4; i++){
        pass[i] = fgetc(keypad_stream);
        fprintf(lcd_stream, "%c", pass[i]);
    }


    if (strcmp(pass, PASSWORD) == 0){
        fprintf(lcd_stream, "\n ACCESS GRANTED");
        fputc('1', green_led_stream);
    } else {
        fprintf(lcd_stream, "\n ACCESS  DENIED");
        fputc('1', red_led_stream);
    }

    fgetc(keypad_stream);
        
    fputc('0', green_led_stream);
    fputc('0', red_led_stream);
    fputc(LCD_DRV_CLEAR, lcd_stream);
};