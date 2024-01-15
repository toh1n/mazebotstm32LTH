void set_motors(int16_t left, int16_t right) {

  if (left >= 0) {
    if (left > LMaxSpeed) left = LMaxSpeed;
    digitalWrite(leftMotorForward, 1);
    digitalWrite(leftMotorBackward, 0);
  }

  else if (left < 0) {
    if (abs(left) > LMaxSpeed) left = 75;

    left = abs(left);
    digitalWrite(leftMotorBackward, 1);
    digitalWrite(leftMotorForward, 0);
  }

  if (right >= 0) {
    if (right > RMaxSpeed) right = RMaxSpeed;

    digitalWrite(rightMotorForward, 0);
    digitalWrite(rightMotorBackward, 1);
  }
  else if (right < 0) {
    if (abs(right) > RMaxSpeed) right = 75;

    right = abs(right);
    digitalWrite(rightMotorForward, 1);
    digitalWrite(rightMotorBackward, 0);
  }

  analogWrite(leftMotorPWM, left);
  analogWrite(rightMotorPWM, right);
}