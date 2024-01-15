void maze_solve() {
  while (1) {
    follow_line();

    readLine();
     if (sensor_values[0] > threshold && sensor_values[1] > threshold && sensor_values[2] > threshold && sensor_values[3] > threshold && sensor_values[4] > threshold && sensor_values[5] > threshold && sensor_values[6] > threshold && sensor_values[7] > threshold) {
      digitalWrite(buzzer, 0);
      digitalWrite(led, 0);
      brake();
      delay(10);
      break;
    }

    // dir = select_turn(found_left, found_straight, found_right);
    // if((found_left && found_right) || found_straight || dir == 'B')
    // {
    // turn(dir);
    // path[path_length] = dir;
    // path_length++;
    // simplify_path();
    // }
    // else {
    //   if (found_left) {
    //   turn('L');
    //   }
    //   else {
    //   turn('R');
    //   }
    // }
    // dir = select_turn(found_left, found_straight, found_right);

    // if(S_turn == 0)
    // {
    //   if (found_left) {
    //   turn('L');
    //   }
    //   else {
    //   turn('R');
    //   }
    // }
    // else {
    // turn(dir);
    // path[path_length] = dir;
    // path_length++;
    // simplify_path();
    // }
    dir = select_turn(found_left, found_straight, found_right);
    turn(dir);
    path[path_length] = dir;
    path_length++;
    simplify_path();
    // for (int i = 0; i<500; i++) {
    // pid(110, 135, p*3, d*3 );
    // i++;
    // }
    

  }
}