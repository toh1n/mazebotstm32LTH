
void read_calibrated() {

  for (int8_t i = 0; i < N_SENS; i++) {
    switchSensor(7 - i);
    delayMicroseconds(20);
    sensor_values[i] = analogRead(PA5);

    int16_t x;
    if (line == BLK) {
    x = mapa(sensor_values[i], sens_min[i], sens_max[i], 0, 1000);
    } else {
      x = mapa(sensor_values[i], sens_min[i], sens_max[i], 1000, 0);
    }
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensor_values[i] = x;
  }
  for(int i = 8;i<10;i++)
  {switchSensor(i);
    timerSensor[i-8] = analogRead(PA5);}
    
}
void switchSensor(uint8_t muxSensor) {
  digitalWrite(PA1, (muxSensor & 1));
  digitalWrite(PA2, (muxSensor & 2));
  digitalWrite(PA3, (muxSensor & 4));
  digitalWrite(PA4, (muxSensor & 8));
}
int16_t mapa(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t read_sensor() {
  for (int8_t i = 0; i < 8; i++) {

    read_calibrated();
    if (sensor_values[7 - i] > 500) {
      bitSet(bitSensor, i);
      // sensor_values[7-i] = 1;
    } else {
      bitClear(bitSensor, i);
      // sensor_values[7-i] = 0;
    }
  }

  // if (line == WHT) {
  //   bitSensor = ~bitSensor;
  //   for(int8_t i=0;i<8;i++){
  //     if(sensor_values[i] == 1){
  //       sensor_values[i] = 0;
  //     }
  //     else {
  //     sensor_values[i] = 1;
  //     }
  //   }
  // }
  return bitSensor;
}


uint16_t readLine() {
  read_calibrated();
  lastPosition = 0;
  return lastPosition;
}