void left() {
  set_motors(-speedturn, speedturn*1.5);
}

void right() {
  set_motors(speedturn*1.5, -speedturn);
}

void straight() {
  set_motors(maxSpeed*.75, maxSpeed);
}

void brake(){
  set_motors(-2, -2);
}

void forward(){ 
  set_motors(maxSpeed *.8, maxSpeed);
}

void backward(){
  set_motors(-maxSpeed, -maxSpeed);
}