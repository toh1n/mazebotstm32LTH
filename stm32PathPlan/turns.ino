void turn(char dir) {
  switch (dir) {

    case 'L':
      brake();
      delay(50);
      left();
      read_calibrated();
      while (sensor_values[0] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[1] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[2] < threshold) {
        read_calibrated();
      }

      brake();
      delay(50);
      break;

    // Turn right 90deg
    case 'R':

      brake();
      delay(50);
      right();
      read_calibrated();
      while (sensor_values[7] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[6] < threshold) {
        read_calibrated();
      }

      while (sensor_values[5] < threshold) {
        read_calibrated();
      }
      brake();
      delay(50);
      break;
    // Turn right 180deg to go back
    case 'B':
      set_motors(-100, -100);
      delay(10);
      brake();
      delay(100);

      left();
      read_calibrated();
      while (sensor_values[0] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[1] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[2] < threshold) {
        read_calibrated();
      }
      brake();
      delay(50);
      break;

    case 'S':
      break;
  }
}



char select_turn(unsigned char found_left, unsigned char found_straight, unsigned char found_right) {

  if (found_left)
    return 'L';
  else if (found_straight)
    return 'S';
  else if (found_right)
    return 'R';
  else
    return 'B';
}



void simplify_path() {

  if (path_length < 3 || path[path_length - 2] != 'B')
    return;

  int16_t total_angle = 0;
  int8_t i;
  for (i = 1; i <= 3; i++) {
    switch (path[path_length - i]) {
      case 'R':
        total_angle += 90;
        break;
      case 'L':
        total_angle += 270;
        break;
      case 'B':
        total_angle += 180;
        break;
    }
  }

  total_angle = total_angle % 360;

  switch (total_angle) {
    case 0:
      path[path_length - 3] = 'S';
      break;
    case 90:
      path[path_length - 3] = 'R';
      break;
    case 180:
      path[path_length - 3] = 'B';
      break;
    case 270:
      path[path_length - 3] = 'L';
      break;
  }
  path_length -= 2;
}
