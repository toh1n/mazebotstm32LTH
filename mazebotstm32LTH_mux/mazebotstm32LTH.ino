//Developed by tohin github:@toh1n email: tohin214@gmail.com
#include "defines.h"

void setup() {

  analogReadResolution(12);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  pinMode(PA4, OUTPUT);
  pinMode(PA0, OUTPUT);
  pinMode(PA5, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(btn, INPUT_PULLUP);

  Wire.setSDA(PB11);
  Wire.setSCL(PB10);
  lcd.begin();
  lcd.setPowerSave(0);
  lcd.setFont(u8x8_font_chroma48medium8_r);
  lcd.clear();

  digitalWrite(led, 0);
  digitalWrite(PA0, 0);
  digitalWrite(PA4, 0);
  Serial1.begin(9600);
}

void loop() {
  lcd.drawString(1, 1, "Maze Solve");
  while (digitalRead(btn) == 1) {
    digitalRead(btn);
  }

  // for(int i=0;i<8;i++){
  // int sensor = read_sensor();
  // Serial1.print(sensor_values[i]);
  // Serial1.print(" ");

  // }
  // Serial1.println();



  // digitalWrite(PC13, 1);
  // brake();
  // delay(3000);
  // set_motors(110, 130);
  // delay(2000);
  // //  for(int i=0;i<100;i++){
  // //    Serial.println(i);
  // //  Serial.println("Hello Tohin!");
  // //  Serial.println("Now Finding the sortest path!!!");
  // //  delay(100);
  // //  }

  line = BLK;

  start_time = millis();
  maze_solve();
  get_back_to_start();
  follow_path();
}
