//Developed by tohin github:@toh1n email: tohin214@gmail.com
#include "defines.h"

char path[] = "SSSSSBRR";

void setup() {
  analogReadResolution(12);
  initRobot();
  Serial1.begin(9600);
}

void loop() {
  line = BLK;
  follow_path();
}
