void left() {
  set_motors(-speedturn, speedturn);
}

void right() {
  set_motors(speedturn, -speedturn);
}

void straight() {
  set_motors(maxSpeed, maxSpeed);
}

void brake() {
  set_motors(-2, -2);
}
