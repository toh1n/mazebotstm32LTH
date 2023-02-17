void follow_path() {
  while (1) {

    brake();
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
    delay(500);

    Serial.println("Taking sortest path.");


    for (int8_t i = 0; i < path_length; i++) {

      follow_line();

      digitalWrite(buzzer, 1);
      digitalWrite(led, 1);

      if (path[i] == 'S') {
        Serial.println("Taking Straight");
        delay(70);
      } else if (path[i] == 'R') {
        Serial.println("Taking Right");
        delay(70);
      } else {
        Serial.println("Taking Left");
        delay(70);
      }

      digitalWrite(buzzer, 0);
      digitalWrite(led, 0);
      turn(path[i]);
    }
    follow_line();
  }
}
