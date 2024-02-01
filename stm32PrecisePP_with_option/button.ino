int8_t button_read() {
  int8_t cl = 0;
p:  uint16_t t = 0;
  if (digitalRead(btn) == 0) {
    digitalWrite(led, HIGH);
    while (digitalRead(btn) == 0) {
      delay(1);t++;
    }
    digitalWrite(led, LOW);
    if (t > 15) {
      t = 0; cl++;
      while (digitalRead(btn) == 1) {
        delay(1); t++;
        if (t > 500) return cl;
      }
      lcd.setCursor(12, 2);
      lcd.print(cl + 1);
      goto p;
    }
  }
  return cl;
}

void calibrate(){
  lcd.drawString(1, 1, "Calibrate");
    while(digitalRead(btn) == 1)
  {
    digitalRead(btn);
  }
  delay(500);
  cal();
  for (int i=0; i<8; i++) {
  Serial1.print(sens_max[i]);
  Serial1.print(" ");
  }
  Serial1.println();
  for (int i=0; i<8; i++) {
  Serial1.print(sens_min[i]);
  Serial1.print(" ");
  }
}

void cal() {
  for (int i = 0; i < 8; i++) {
    sens_max[i] = 0;
    sens_min[i] = 4096;
  }
  set_motors(100, -100);
  for (int i = 0; i < 5000 ; i++) {
    for (int i = 0; i < 8 ; i++) {
      switchSensor(i);
      delayMicroseconds(20);
      sensor_values[i] = analogRead(PA5);
      sens_max[i] = max(sens_max[i], sensor_values[i]);
      sens_min[i] = min(sens_min[i], sensor_values[i]);
    }
  }
  set_motors(0, 0);
}