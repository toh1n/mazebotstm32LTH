void line_follow()  //follow the line
{
  while (1) {

    lineBreak = 0;
    pid(maxSpeed, p, d);

    read_calibrated();
    if (sensor_values[0] > threshold && sensor_values[2] + sensor_values[3] + sensor_values[4] > threshold) {

      deadEnd = 0;
      straight();
      return;
    }

    read_calibrated();
    if (sensor_values[7] > threshold && (sensor_values[3] + sensor_values[4] < threshold) && sensor_values[0] > threshold) {

      deadEnd = 0;
      straight();
      return;
    }

    read_calibrated();
    if (sensor_values[7] > threshold && sensor_values[3] + sensor_values[4] + sensor_values[5] > threshold) {

      deadEnd = 0;
      straight();
      return;
    }

    read_calibrated();
    if (sensor_values[0] < threshold && sensor_values[1] < threshold && sensor_values[2] < threshold && sensor_values[3] < threshold && sensor_values[4] < threshold && sensor_values[5] < threshold && sensor_values[6] < threshold && sensor_values[7] < threshold) {

      uint32_t m3 = millis();
      while (millis() - m3 < m6) {
        pid(maxSpeed * .8, p * 3, d * 3);
        // straight();
        read_calibrated();
        if (sensor_values[0] + sensor_values[1] + sensor_values[2] + sensor_values[3] + sensor_values[4] + sensor_values[5] + sensor_values[6] + sensor_values[7] > threshold) {
          lineBreak = 1;
          brake();
          delay(5);
          break;
        }
      }

      if (lineBreak == 0) {
        deadEnd = 1;
        lineBreak = 0;
        brake();
        delay(10);
        return;
      }
    }
  }
}

void pid(uint16_t SPEED, uint8_t kp, uint8_t kd) {

  bitSensor = read_sensor();
  int8_t errorSensor[8] = { -15, -10, -5, -1, 1, 5, 10, 15 };
  int8_t onSensor[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  int8_t sumOnSensor = 0;
  for (int8_t i = 0; i < 8; i++) {
    onSensor[i] = bitRead(bitSensor, i);
    sumOnSensor += onSensor[i];
    errorSensor[i] = errorSensor[i] * onSensor[i];
    error += errorSensor[i];
  }
  error = error / sumOnSensor;

  int16_t rateError = error - lastError;
  lastError = error;

  int16_t moveVal = int((error * kp) + (rateError * kd));
  int16_t moveLeft = SPEED - moveVal;
  int16_t moveRight = SPEED + moveVal;

  set_motors(moveLeft, moveRight);
}



// void line_follow()  //follow the line
// {
//   while (1) {

//     lineBreak = 0;
//     pid(maxSpeed, p, d);

//     if (onSensor[0] == 1 && onSensor[9] == 0) {
//       delay(20);
//       turn('R');
//     }
//     if (onSensor[9] == 1 && onSensor[1] == 0) {

//       delay(20);
//       turn('L');
      
//     }

//   }
// }

// void pid(uint16_t SPEED, uint8_t kp, uint8_t kd) {

//   bitSensor = read_sensor();
//   int8_t errorSensor[10] = { -8,-6, -4, -2, -1, 1, 2, 4, 6, 8 };
//   int8_t onSen[10] = { 0,0,0, 0, 0, 0, 0, 0, 0, 0 };
//   int8_t sumOnSensor = 0;
//   for (int8_t i = 0; i < 10; i++) {
//     sumOnSensor += onSensor[i];
//     errorSensor[i] = errorSensor[i] * onSensor[i];
//     error += errorSensor[i];
//   }
//   error = error / sumOnSensor;

//   int16_t rateError = error - lastError;
//   lastError = error;

//   int16_t moveVal = int((error * kp) + (rateError * kd));
//   int16_t moveLeft = SPEED - moveVal;
//   int16_t moveRight = SPEED + moveVal;

//   set_motors(moveLeft, moveRight);
// }
