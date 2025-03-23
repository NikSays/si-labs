#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#include <button.h>
#include <led.h>
#include <serial.h>

#define BUTTON_PIN 50
#define LED1_PIN 30
#define LED2_PIN 31

extern SemaphoreHandle_t semaphore; 
extern QueueHandle_t queue;   

extern FILE *led_1_stream;
extern FILE *led_2_stream;
extern FILE *serial_stream;
extern FILE *button_stream;

// Prevent optimisation
extern volatile int blinks;

void lab_2_2_setup();

void lab_2_2_task_1(void *);
void lab_2_2_task_2(void *);
void lab_2_2_task_3(void *);