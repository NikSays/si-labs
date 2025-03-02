#define LAB_1_2

#ifdef LAB_1_1
#include "lab_1_1/lab.h"
void setup() {lab_1_1_setup();}
void loop() {lab_1_1_loop();}
#endif

#ifdef LAB_1_2
#include "lab_1_2/lab.h"
void setup() {lab_1_2_setup();}
void loop() {lab_1_2_loop();}
#endif