#define LAB_2_2

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

#ifdef LAB_2_1
#include "lab_2_1/lab.h"
void setup() {lab_2_1_setup();}
void loop() {lab_2_1_loop();}
#endif

#ifdef LAB_2_2
#include "lab_2_2/lab.h"
void setup() {lab_2_2_setup();}
void loop() {}
#endif