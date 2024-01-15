void follow_line()  //follow the line
{
  while (1) {

    lineBreak = 0;

 
    int8_t binSensor = readLine();
    if (sensor_values[0] > threshold && sensor_values[3] + sensor_values[4] > threshold) {

      deadEnd = 0;
      straight();
      left_right();
      if (found_cross == 1) {
        return;
      }
    }

//     readLine();
//     if (sensor_values[7] > threshold && (sensor_values[3] + sensor_values[4] < threshold) && sensor_values[0] > threshold) {

//       deadEnd = 0;
//       straight();
//       left_right();
//       if (found_cross == 1) {
//         return;
//       }
//     }

    

    readLine();
    if (sensor_values[7] > threshold && sensor_values[3] + sensor_values[4] > threshold) {

      deadEnd = 0;
      straight();
      left_right();
      if (found_cross == 1) {
        return;
      }
    }

//     readLine();
//     if ((sensor_values[7] + sensor_values[6] > threshold) && (sensor_values[3] < threshold && sensor_values[4] < threshold) && (sensor_values[0] + sensor_values[1] > threshold)) {

//       deadEnd = 0;
//       straight();
//       left_right();
//       if (found_cross == 1) {
//         return;
//       }
//     }

    // readLine();
    // if (sensor_values[0] < threshold && sensor_values[1] < threshold && sensor_values[2] < threshold && sensor_values[3] < threshold && sensor_values[4] < threshold && sensor_values[5] < threshold && sensor_values[6] < threshold && sensor_values[7] < threshold) {

    //   uint32_t m3 = millis();
    //   int t = 0;
    //   while (t<150) {
    //     // pid(LMaxSpeed,RMaxSpeed, p*2, d*2);
    //     straight();
    //     readLine();
    //     if (sensor_values[0] + sensor_values[1] + sensor_values[2] + sensor_values[3] + sensor_values[4] + sensor_values[5] + sensor_values[6] + sensor_values[7] > threshold) {
    //       lineBreak = 1;
    //       brake();
    //       delay(5);
    //       // if (timerSensor[1] > 3500) {
    //       //   lineBreak = 1;
    //       //   turn('L');
    //       //   break;
    //       // }
    //       // if (timerSensor[0] > 3500) {
    //       //   lineBreak = 1;
    //       //   turn('R');
    //       //   break;
    //       // }
    //       break;
    //     }
    //     t++;
    //     delay(1);
    //   }

    //   if (lineBreak == 0) {
    //     deadEnd = 1;
    //     lineBreak = 0;
    //     brake();
    //     delay(10);
    //     left_right();
    //     if (found_cross == 1) {
    //       return;
    //     }
    //   }
    // }

    pid(LMaxSpeed, RMaxSpeed, p, d);

  // uint32_t NOW = millis();
  // uint32_t interval = NOW - lastTime;
  // if (interval >= 10) {
  //   pid(LMaxSpeed, RMaxSpeed, p, d);
  // }
  // lastTime = NOW;
  }
}

void pid(uint16_t LSPEED, uint16_t RSPEED, uint8_t kp, uint8_t kd) {

  bitSensor = read_sensor();
  int8_t errorSensor[8] = { -70, -10, -5, -1, 1, 5, 10, 70 };
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
  // if (sumOnSensor > 2 || sumOnSensor == 0) {
  //   moveVal = 0;
  // }
  int16_t moveLeft = LSPEED - moveVal;
  int16_t moveRight = RSPEED + moveVal;

  set_motors(moveLeft, moveRight);
}
void left_right() {
  digitalWrite(buzzer, 1);
  digitalWrite(led, 0);

  found_left = 0;
  found_straight = 0;
  found_right = 0;

  if (deadEnd == 0) {

    readLine();
    if (sensor_values[0] + sensor_values[1] > 400) {
      found_left = 1;

      while (sensor_values[0] > 300 && sensor_values[7] < 300) {
        readLine();
      }
    }


    readLine();
    if (sensor_values[7] + sensor_values[6] > 400) {

      found_right = 1;

      while (sensor_values[7] > 300 && sensor_values[0] < 300) {
        readLine();
      }
    }


    int32_t m2 = millis();
    if(found_left && !found_right){
      while (timerSensor[0] < 3500) {
      pid(LMaxSpeed, RMaxSpeed, p, d);
      // straight();
      readLine();
      if (sensor_values[0] > threshold) {
        found_left = 1;
      }
      readLine();
      if (sensor_values[7] > threshold) {

        found_right = 1;
      }
    }
    }
    else{
      while (timerSensor[1] < 3500) {
      pid(LMaxSpeed, RMaxSpeed, p, d);
      // straight();
      readLine();
      if (sensor_values[0] > threshold) {
        found_left = 1;
      }
      readLine();
      if (sensor_values[7] > threshold) {

        found_right = 1;
      }
    }
    }
    
    // brake();
    // delay(150);



    readLine();
    if (sensor_values[2] + sensor_values[3] + sensor_values[4] + sensor_values[5] > threshold) {
      found_straight = 1;
      // Serial.println("Found Straight --");
    }

    if (found_left && found_right) {
      straight();
      delay(20);
    }


    digitalWrite(buzzer, 0);
    digitalWrite(led, 1);
    brake();
  }

  if (deadEnd) {
    brake();
    delay(10);
  }
  found_cross = 0;
  // if (found_left && !found_right) {
  //     turn('L');
  //   } else {
  //     turn('R');
  //   }
  dir = select_turn(found_left, found_straight, found_right);
  if ((found_left && found_right) || found_straight || dir == 'B') {
    found_cross = 1;
  } else {
    if (found_left) {
      turn('L');
    } else {
      turn('R');
    }
  } 
}