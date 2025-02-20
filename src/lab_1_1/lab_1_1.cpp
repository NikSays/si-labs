#include "lab_1_1.h"
#define LED_PIN LED_BUILTIN

FILE *serial_stream;
FILE *led_stream;

int builtin_led_putchar(char ch, FILE *) {
    return led_putchar(LED_PIN, ch);
}

void lab_setup() {
    serial_setup();
    led_setup(LED_PIN);

    // Open streams for STDIO
    serial_stream = fdevopen(serial_putchar, serial_getchar);
    led_stream = fdevopen(builtin_led_putchar, NULL);
};

void lab_loop() {
    char c = 0;
    char str[64] = {0};
    int i = 0;

    fprintf(serial_stream, "Enter command: ");

    // Leave 64th char as 0 (null terminator)
    while (i < 63) {
        // Read and echo the character
        c = fgetc(serial_stream);
        fputc(c, serial_stream); 

        // Stop reading on newline characters
        if (c  == '\r' || c == '\n') break;

        // Add to string
        str[i] = c; 
        i++;
    }
    // If CRLF was sent, the CR was read but LF is still in input buffer
    // If more than 63 characters were typed, the rest are still in the buffer
    while (c != '\n') c = fgetc(serial_stream);

    // Echo the skipped newline
    fprintf(serial_stream, "\n"); 

    // Parse command
    if (strcmp(str, "led on") == 0){
        fputc('1', led_stream);
        fprintf(serial_stream, "Turning the LED on!\n");
    } else if (strcmp(str, "led off") == 0) {
        fputc('0', led_stream);
        fprintf(serial_stream, "Turning the LED off!\n");
    } else {
        fprintf(serial_stream, "Unknown command.\n");
    }

    // Print newline to split iterations in terminal
    fputc('\n', serial_stream);
};
