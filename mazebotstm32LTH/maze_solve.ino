void maze_solve() {
  while (1) {
    follow_line();

    digitalWrite(buzzer, 1);
    digitalWrite(led, 0);

    unsigned char found_left = 0;
    unsigned char found_straight = 0;
    unsigned char found_right = 0;

    if (deadEnd == 0) {

      readLine();
      if (sensor_values[0] + sensor_values[1] > 400) {
        found_left = 1;

        while (sensor_values[0] > 300 && sensor_values[7] < 300) {
          readLine();
        }
      }


      readLine();
      if (sensor_values[7] + sensor_values[6] > 400) {

        found_right = 1;

        while (sensor_values[7] > 300 && sensor_values[0] < 300) {
          readLine();
        }
      }


      int32_t m2 = millis();
      while (millis() - m2 < m1) {

        pid(maxSpeed, p, d);
        readLine();
        if (sensor_values[0] > threshold) {
          found_left = 1;
        }
        readLine();
        if (sensor_values[7] > threshold) {

          found_right = 1;
        }
      }



      readLine();
      if (sensor_values[2] + sensor_values[3] + sensor_values[4] + sensor_values[5] > threshold) {
        found_straight = 1;
        Serial.println("Found Straight --");
      }


      digitalWrite(buzzer, 0);
      digitalWrite(led, 1);
      brake();
    }

    if (deadEnd) {
      brake();
      delay(10);
    }


    readLine();
    if (sensor_values[0] > threshold && sensor_values[1] > threshold && sensor_values[2] > threshold && sensor_values[3] > threshold && sensor_values[4] > threshold && sensor_values[5] > threshold && sensor_values[6] > threshold && sensor_values[7] > threshold) {
      digitalWrite(buzzer, 0);
      digitalWrite(led, 0);
      brake();
      delay(10);
      break;
    }
    dir = select_turn(found_left, found_straight, found_right);
    turn(dir);
    path[path_length] = dir;
    path_length++;
    simplify_path();
  }
}