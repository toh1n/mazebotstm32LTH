void bluetoothControl() {
  String inputString = "";
  String command = "";
  String value = "";
  boolean stringComplete = false;

  char btCommand = 'S';
  char prevCommand = 'A';
  int velocity = 0;
  unsigned long timer0 = 2000;  //Stores the time (in millis since execution started)
  unsigned long timer1 = 0;     //Stores the time when the last command was received from the phone
  lcd.drawString(1, 1, "Blutooth Mode");

  while (1) {
    if (Serial1.available() > 0) {
      prevCommand = btCommand;
      btCommand = Serial1.read();
      //Change pin mode only if new command is different from previous.
      if (btCommand != prevCommand) {
        //Serial.println(command);
        switch (btCommand) {
          case 'F':
            forward();
            break;
          case 'B':
            backward();
            break;
          case 'L':
            left();
            break;
          case 'R':
            right();
            break;
          case 'S':
            brake();
            break;
          case 'I':  //FR
            right();
            break;
          case 'G':  //FL
            left();
            break;
          case 'J':  //BR
            left();
            break;
          case 'H':  //FR
            right();
            break;
          default:  //Get velocity
            if (btCommand == 'q') {
              velocity = 255;  //Full velocity
              maxSpeed = velocity;
            } else {
              //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
              if ((btCommand >= 48) && (btCommand <= 57)) {
                //Subtracting 48 changes the range from 48-57 to 0-9.
                //Multiplying by 25 changes the range from 0-9 to 0-225.
                velocity = (btCommand - 48) * 25;
                maxSpeed = velocity;
                lcd.setCursor(3, 3);
                lcd.print(maxSpeed);
              }
            }
        }
      }
    }
  }
}
