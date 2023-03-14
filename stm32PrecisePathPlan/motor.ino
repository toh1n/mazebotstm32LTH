void set_motors(int16_t left, int16_t right) {

  if (left >= 0) {
    if (left > maxSpeed) left = maxSpeed;

    digitalWrite(leftMotorForward, 1);
    digitalWrite(leftMotorBackward, 0);
  }

  if (left < 0) {
    if (abs(left) > maxSpeed) left = maxSpeed;

    left = abs(left);
    digitalWrite(leftMotorBackward, 1);
    digitalWrite(leftMotorForward, 0);
  }

  if (right >= 0) {
    if (right > maxSpeed) right = maxSpeed;

    digitalWrite(rightMotorForward, 1);
    digitalWrite(rightMotorBackward, 0);
  }
  if (right < 0) {
    if (abs(right) > maxSpeed) right = maxSpeed;

    right = abs(right);
    digitalWrite(rightMotorForward, 0);
    digitalWrite(rightMotorBackward, 1);
  }

  analogWrite(leftMotorPWM, left);
  analogWrite(rightMotorPWM, right);
}