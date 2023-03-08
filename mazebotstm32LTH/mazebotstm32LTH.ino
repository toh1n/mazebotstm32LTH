//Developed by tohin github:@toh1n email: tohin214@gmail.com
#include "defines.h"

void setup() {

  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  digitalWrite(led, 0);
  Serial.begin(9600);
}

void loop() {


  while (digitalRead(btn) == 1) {
    digitalRead(btn);
  }


  digitalWrite(PC13, 1);

  delay(1000);
  //  for(int i=0;i<100;i++){
  //    Serial.println(i);
  //  Serial.println("Hello Tohin!");
  //  Serial.println("Now Finding the sortest path!!!");
  //  delay(100);
  //  }

  maze_solve();
  get_back_to_start();
  follow_path();
}
