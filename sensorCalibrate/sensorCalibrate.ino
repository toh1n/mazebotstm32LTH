#include "defines.h"
int maximum[8];
int minimum[8];
int s[8];
#define btn PB5

void setup() {
  analogReadResolution(12);
  initRobot();
  Serial1.begin(9600);
  line = BLK;
}

void loop() {
  while(digitalRead(btn) == 1)
  {
    digitalRead(btn);
  }
  delay(500);
  cal();
  for (int i=0; i<8; i++) {
  Serial1.print(maximum[i]);
  Serial1.print(" ");
  }
  Serial1.println();
  for (int i=0; i<8; i++) {
  Serial1.print(minimum[i]);
  Serial1.print(" ");
  }
}

void cal() {
  for (int i = 0; i < 8; i++) {
    maximum[i] = 0;
    minimum[i] = 4096;
  }
  set_motors(100, -100);
  for (int i = 0; i < 5000 ; i++) {
    for (int i = 0; i < 8 ; i++) {
      switchSensor(i);
      delayMicroseconds(20);
      s[i] = analogRead(PA5);
      maximum[i] = max(maximum[i], s[i]);
      minimum[i] = min(minimum[i], s[i]);
    }
  }
  set_motors(0, 0);
}
void switchSensor(uint8_t muxSensor) {
  digitalWrite(PA1, (muxSensor & 1));
  digitalWrite(PA2, (muxSensor & 2));
  digitalWrite(PA3, (muxSensor & 4));
  digitalWrite(PA4, (muxSensor & 8));
}