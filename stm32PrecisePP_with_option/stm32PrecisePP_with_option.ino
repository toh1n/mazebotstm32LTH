//Developed by tohin github:@toh1n email: tohin214@gmail.com
#include "defines.h"

char full_path[] = "SLBLSLSLSGBGL";
char c1[] = "SSLSLSGBGL";
char c2[] = "SLBLSLLBLSRR";
char c3[] = "BGL";
char btCommand;

void setup() {
  analogReadResolution(12);
  initRobot();
  Serial1.begin(9600);
  // for(int8_t i=0;i<10;i++)
  // {
  //   sens_mid[i] = ((sens_max[i] + sens_min[i]) / 2);
  // }
  line = BLK;
}

void loop() {
  int8_t b = button_read();

  lcd.drawString(2, 0, "Precise Path");
  lcd.drawString(0, 2, "1.Full Lap");
  lcd.drawString(0, 3, "2.C1");
  lcd.drawString(0, 4, "3.C2");
  lcd.drawString(0, 5, "4.C3");
  lcd.drawString(0, 6, "5.Read ADC");
  

  if (b != 0) {
    lcd.clear();
    if (b == 1) {
      uint16_t path_length = *(&full_path + 1) - full_path;
      follow_path(full_path, path_length,1);
    } 
    else if (b == 2) {
      uint16_t path_length = *(&c1 + 1) - c1;
      follow_path(c1, path_length,2);
    }
    else if (b == 3) {
      uint16_t path_length = *(&c2 + 1) - c2;
      follow_path(c2, path_length,3);
    }
    else if (b == 4) {
      uint16_t path_length = *(&c3 + 1) - c3;
      follow_path(c3, path_length,4);
    }
    else if (b == 5) {
      sensor_read();
    }
    else if (b == 6) {
      lcd.clear();
      line_select();
    }
    else if (b == 7) {
      lcd.clear();
      motor_test();
    }
    else if (b == 8) {
      lcd.clear();
      bluetoothControl();
    }
  }


  // int8_t i = 0;
  // while (1) {
  // if (Serial1.available() > 0) {
  //   btCommand = Serial1.readString();
  //   if (btCommand == 'D') {
  //   break;
  //   }
  //   else {
  //   path[i] = btCommand;
  //   lcd.setCursor(5, 5);
  //   lcd.print(btCommand);
  //   i = i+1;
  //   }


  // }
  // }

  // lcd.clear();
  // lcd.setCursor(5, 5);
  // lcd.print(b);
  // line = BLK;
  // follow_path();
}

void motor_test(){
  while (1) {
    lcd.draw1x2String(2, 2, "Motor Test");

  int8_t b = button_read();
  if(b == 1)
  {
    set_motors(150, 150);
  }
  else if (b == 2) {
  set_motors(-150, -150);
  }
  else if (b == 3) {
  return;
  }
  }
  
}