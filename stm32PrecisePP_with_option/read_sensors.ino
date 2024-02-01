
void read_calibrated() {

  switchSensor(9);
  delayMicroseconds(20);
  sensor_values[0] = analogRead(PA5);

  for (int8_t i = 1; i < 10; i++) {
    switchSensor(i-1);
    delayMicroseconds(20);
    sensor_values[i] = analogRead(PA5);
  }

  for(int8_t i = 0 ;i<10;i++)
  {
    int16_t x;
    if (line == BLK) {
    x = scale(sensor_values[i], sens_min[i], sens_max[i], 0, 1000);
    } else {
      x = scale(sensor_values[i], sens_min[i], sens_max[i], 1000, 0);
    }
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensor_values[i] = x;
  }

}
void switchSensor(uint8_t muxSensor) {
  digitalWrite(PA1, (muxSensor & 1));
  digitalWrite(PA2, (muxSensor & 2));
  digitalWrite(PA3, (muxSensor & 4));
  digitalWrite(PA4, (muxSensor & 8));
}
int16_t scale(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t read_sensor() {
  
  for (int8_t i = 0; i < 10; i++) {
  onSensor[i] = 0;
  }    
  for (int8_t i = 0; i < 10; i++) {
    read_calibrated();
    if (sensor_values[i] > 500) {
      bitSet(bitSensor, i);
      onSensor[i] = 1;

    } else {
      bitClear(bitSensor, i);
      onSensor[i] = 0;
    }
  }
  return bitSensor;
}


void sensor_read(){
  while (1){
  uint16_t bitS = read_sensor();
  uint16_t highBar[10], showBar[10];
  pid(0, 0, 0);
  for (int8_t i = 0; i < 10; i++) {
    showBar[i] = map(sensor_values[9-i], 0, 1000, 0, 7);
    lcd.drawTile(i+3, 3, 1, bar[showBar[i]]);
    lcd.setCursor(i+3, 5);
    lcd.print(onSensor[9-i]);
    
  }
  lcd.setCursor(3, 1);
  lcd.print(error);
  delayMicroseconds(20);
  }
}

void line_select() {
  while (1) {
    lcd.drawString(1, 1, "Line");
    int8_t b = button_read();
    if (b == 1) {
      line = BLK;
    } else if (b == 2) {
      line = WHT;
    }
    if (line == BLK ) {
    lcd.draw2x2String(2, 2, "BLK");
    }
    else if (line == WHT) {
    lcd.draw2x2String(2, 2, "WHT");
    }
    if (b == 3) {
      lcd.clear();
    return;
    }
  }
}