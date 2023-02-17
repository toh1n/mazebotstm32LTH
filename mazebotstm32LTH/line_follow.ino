void follow_line()  //follow the line
{
  while (1) {

    lineBreak = 0;
    pid(maxSpeed, p, d);

    readLine();
    if (sensor_values[0] > threshold && sensor_values[2] + sensor_values[3] + sensor_values[4] > threshold) {

      deadEnd = 0;
      straight();
      return;
    }

    readLine();
    if (sensor_values[7] > threshold && (sensor_values[3] + sensor_values[4] < threshold) && sensor_values[0] > threshold) {

      deadEnd = 0;
      straight();
      return;
    }

    readLine();
    if (sensor_values[7] > threshold && sensor_values[3] + sensor_values[4] + sensor_values[5] > threshold) {

      deadEnd = 0;
      straight();
      return;
    }

    readLine();
    if (sensor_values[0] < threshold && sensor_values[1] < threshold && sensor_values[2] < threshold && sensor_values[3] < threshold && sensor_values[4] < threshold && sensor_values[5] < threshold && sensor_values[6] < threshold && sensor_values[7] < threshold) {

      uint32_t m3 = millis();
      while (millis() - m3 < m6) {
        straight();
        readLine();
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
  int8_t errorSensor[8] = { -14, -10, -5, -1, 1, 5, 10, 14 };
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
