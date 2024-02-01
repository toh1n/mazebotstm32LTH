void line_follow()  //follow the line
{
  while (1) {

    lineBreak = 0;
    pid(maxSpeed, p, d);

    if (onSensor[0] == 1 && onSensor[9] == 0) {
      delay(20);
      turn('R');
    }
    if (onSensor[9] == 1 && onSensor[1] == 0) {

      delay(20);
      turn('L');
      
    }

  }
}

void pid(uint16_t SPEED, uint8_t kp, uint8_t kd) {

  bitSensor = read_sensor();
  int8_t errorSensor[10] = { -8,-6, -4, -2, -1, 1, 2, 4, 6, 8 };
  int8_t onSen[10] = { 0,0,0, 0, 0, 0, 0, 0, 0, 0 };
  int8_t sumOnSensor = 0;
  for (int8_t i = 0; i < 10; i++) {
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
