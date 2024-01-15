void left() {
  set_motors(-speedturn, speedturn);
}

void right() {
  set_motors(speedturn, -speedturn);
}

void straight() {
  set_motors(LMaxSpeed, RMaxSpeed);
}

void brake(){
  set_motors(-2, -2);
}

void forward(){ 
  set_motors(LMaxSpeed, RMaxSpeed);
}

void backward(){
  set_motors(-LMaxSpeed, -RMaxSpeed);
}
// void brake() {
//   digitalWrite(leftMotorForward, 1);
//   digitalWrite(leftMotorBackward, 1);

//   digitalWrite(rightMotorForward, 1);
//   digitalWrite(rightMotorBackward, 1);

//   analogWrite(leftMotorPWM, maxSpeed);
//   analogWrite(rightMotorPWM, maxSpeed);
// }
