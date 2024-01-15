void get_back_to_start() {

  Serial1.print("Sortest path : ");
  Serial1.print(" ");
  Serial1.println();

  
  rotate180();

  int8_t j = 0;
  for (int8_t i = path_length - 1; i >= 0; i--) {
    if (path[i] == 'L') {
      reverse_path[j] = 'R';
    } else if (path[i] == 'R') {
      reverse_path[j] = 'L';
    } else if (path[i] == 'S') {
      reverse_path[j] = 'S';
    } else {
      reverse_path[j] = 'B';
    }
    j++;
  }

  Serial1.print("Sortest reverse path : ");
  Serial1.print(" ");
  for (int8_t i = 0; i < path_length; i++) {
    Serial.print(reverse_path[i]);
    Serial.print(" ");
  }
  Serial1.println();


  for (int8_t i = 0; i < path_length; i++) {

    follow_line();
    digitalWrite(buzzer, 1);
    digitalWrite(led, 1);

    if (reverse_path[i] == 'S') {
      Serial.println("Taking Straight");
      delay(60);
    } else if (reverse_path[i] == 'R') {
      Serial.println("Taking Right");
      delay(60);
    } else {
      Serial.println("Taking Left");
      delay(60);
    }


    turn(reverse_path[i]);
    digitalWrite(buzzer, 0);
    digitalWrite(led, 0);
  }
  follow_line();
  turn('B');
  Serial1.println("Done!");
}

void rotate180() {

  brake();
  delay(400);
  set_motors(-LMaxSpeed, -RMaxSpeed);
  delay(100);

  line_position = readLine();
  while (sensor_values[7] > threshold && sensor_values[6] > threshold && sensor_values[1] > threshold && sensor_values[0] > threshold)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }
  //  line_position = readLine();
  //  while (sensor_values[0] > threshold)  // wait for outer most sensor to find the line
  //  {
  //    line_position = readLine();
  //  }
  brake();
  delay(10);
  right();
  line_position = readLine();
  while (sensor_values[7] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }

  line_position = readLine();
  while (sensor_values[6] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }

  line_position = readLine();
  while (sensor_values[4] < threshold || sensor_values[3] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }

  brake();
  delay(100);
}


