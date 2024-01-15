void follow_path() {
  while (1) {
    brake();
    delay(10);

    stop_time = millis();
    uint32_t lap = (stop_time - start_time) / 10;
    float lap_f = float(lap) / 100.0;
    lcd.clear();
    lcd.drawString(0, 1, "Time: ");
    lcd.setCursor(6, 1); lcd.print(lap_f);
    lcd.drawString(10, 1, "s");


    lcd.setCursor(0, 3); lcd.print("Sortest path : ");
    for(int8_t i=0;i<path_length;i++)
    {
      
      if (3+i > 12) {
      lcd.setCursor(1+i,6);
      lcd.print(path[i]);
      }
      else {
      lcd.setCursor(1+i, 5);
      lcd.print(path[i]);
      }
    }

    delay(20);
    for (int8_t i = 0; i < 5; i++) {
      digitalWrite(led, 0);
      delay(200);
      digitalWrite(led, 1);
      delay(200);
    }

    

    while (digitalRead(btn) == 1) {
      digitalRead(btn);
    }
    // delay(3000);

    Serial1.println("Taking sortest path.");


    for (int8_t i = 0; i < path_length; i++) {
      follow_line();
      brake();
      delay(10);
      straight();


      digitalWrite(buzzer, 1);
      digitalWrite(led, 1);

      // if (path[i] == 'S') {
      //   Serial1.println("Taking Straight");
      //   delay(70);
      // } else if (path[i] == 'R') {
      //   Serial1.println("Taking Right");
      //   delay(70);
      // } else {
      //   Serial1.println("Taking Left");
      //   delay(70);
      // }

      digitalWrite(buzzer, 0);
      digitalWrite(led, 0);
      turn(path[i]);
    }
    follow_line();
    get_back_to_start();
  }
}


