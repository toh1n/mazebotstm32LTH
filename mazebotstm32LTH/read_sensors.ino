
void read_calibrated() {

  for (int8_t i = 0; i < N_SENS; i++) {
    sensor_values[i] = analogRead(sensor[i]);
    int16_t x = mapa(sensor_values[i], sens_min[i], sens_max[i], 0, 1000);
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensor_values[i] = x;
  }
}

int16_t mapa(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t read_sensor() {
  for (int8_t i = 0; i < 8; i++) {

    read_calibrated();
    if (sensor_values[7 - i] > 500) {
      bitSet(bitSensor, i);
    } else {
      bitClear(bitSensor, i);
    }
  }

  // if (line == WHT) {
  //   bitSensor = ~bitSensor;
  // }
  return bitSensor;
}


uint16_t readLine() {
  read_calibrated();
  lastPosition = 0;
  return lastPosition;
}