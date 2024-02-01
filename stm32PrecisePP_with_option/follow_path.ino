void follow_path(char *path, uint16_t path_length, int8_t n) {
  while (1) {

    // brake();
    // delay(10);
    lcd.clear();
    if (n == 1) {
      lcd.setCursor(0, 1);
      lcd.print("Full Lap :");
    } else if (n == 2) {
      lcd.setCursor(0, 1);
      lcd.print("C1");
    } else if (n == 3) {
      lcd.setCursor(0, 1);
      lcd.print("C2");
    } else if (n == 4) {
      lcd.setCursor(0, 1);
      lcd.print("C3");
    }

    for (uint16_t i = 0; i < path_length; i++) {
      lcd.setCursor(1 + i, 4);
      lcd.print(path[i]);
    }

    while (digitalRead(btn) == 1) {
      digitalRead(btn);
    }
    start_time = millis();
    delay(500);

    for (uint16_t i = 0; i < path_length; i++) {
      line_follow();
      digitalWrite(buzzer, 1);
      digitalWrite(led, 1);

      int32_t m2 = millis();

      if (path[i] == 'B') {

      } else if (path[i] == 'G' || path[i] == 'W' || path[i] == 'X') {
        straight();
        delay(70);
      } else {
        while (millis() - m2 < m1) {
          straight();
        }
      }


      if (path[i] == 'S') {
        Serial1.println("Taking Straight");
      } else if (path[i] == 'R') {
        Serial1.println("Taking Right");
      } else if (path[i] == 'L') {
        Serial1.println("Taking Left");
      } else {
        Serial1.println("G");
      }
      // delay(60);


      digitalWrite(buzzer, 0);
      digitalWrite(led, 0);
      turn(path[i]);
    }
    brake();

    stop_time = millis();
    uint32_t lap = (stop_time - start_time) / 10;
    float lap_f = float(lap) / 100.0;
    lcd.clear();
    lcd.drawString(0, 1, "Done!");
    lcd.drawString(0, 3, "Time: ");
    lcd.setCursor(6, 3);
    lcd.print(lap_f);
    lcd.drawString(10, 3, "s");
    while (digitalRead(btn) == 1) {
      digitalRead(btn);
    }
    delay(500);
  }
}
