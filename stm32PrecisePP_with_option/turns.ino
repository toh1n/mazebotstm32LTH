void turn(char dir) {
  switch (dir) {

    case 'L':
      brake();
      delay(50);
      left();
      read_calibrated();
      while (sensor_values[8] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[7] < threshold) {
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
    // Turn right 180deg to go back
    case 'B':
      // set_motors(-100, -100);
      // delay(10);
      brake();
      delay(100);

      left();
      read_calibrated();
      while (sensor_values[8] < threshold) {
        read_calibrated();
      }

      read_calibrated();
      while (sensor_values[7] < threshold) {
        read_calibrated();
      }

      brake();
      delay(50);
      break;

    case 'S':
      break;
    case 'G':
      brake();
      delay(50);
      straight();
      read_calibrated();
      while (sensor_values[1] > threshold && sensor_values[2] > threshold && sensor_values[3] > threshold && sensor_values[4] > threshold && sensor_values[5] > threshold && sensor_values[6] > threshold && sensor_values[7] > threshold) {
        read_calibrated();
        // set_motors(50, 120);
      }
      // while (sensor_values[0] < threshold || sensor_values[7] < threshold) {
      // set_motors(50, 120);
      // }
      // set_motors(50, 120);
      // brake();
      straight();
      delay(80);
      brake();
      delay(10);
      break;
    case 'W':
    line = WHT;
    case 'X':
    line = BLK;
  }
}