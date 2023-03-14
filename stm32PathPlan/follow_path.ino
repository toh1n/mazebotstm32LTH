void follow_path() {
  while (1) {

    // brake();
    // delay(10);
    lcd.clear();
    uint16_t path_length = *(&path + 1) - path;
    lcd.setCursor(1, 1);
    lcd.print("Path :");
    for (uint16_t i = 0; i < path_length; i++) {

      if (3 + i > 12) {
        lcd.setCursor(1 + i, 3);
        lcd.print(path[i]);
      } else {
        lcd.setCursor(1 + i, 4);
        lcd.print(path[i]);
      }
    }

    while (digitalRead(btn) == 1) {
      digitalRead(btn);
    }
    start_time = millis();
    delay(500);
    
    for (uint16_t i = 0; i < path_length; i++) {
      line_follow();
      digitalWrite(buzzer, 0);
      digitalWrite(led, 0);
      turn(path[i]);
    }
    line_follow();
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
  }
}
