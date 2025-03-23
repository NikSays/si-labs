#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#include <serial.h>

#define SENSOR_PIN A15

void lab_3_1_setup();

void lab_3_1_task_1(void *);
void lab_3_1_task_2(void *);