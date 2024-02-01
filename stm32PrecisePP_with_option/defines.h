//Developed by tohin github:@toh1n email: tohin214@gmail.com
#include <Wire.h>
#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_HW_I2C lcd(U8X8_PIN_NONE);

#define rightMotorForward PB4
#define rightMotorBackward PB15
#define rightMotorPWM PA8
#define leftMotorForward PB12
#define leftMotorBackward PB13
#define leftMotorPWM PB14
#define led PC13
#define buzzer PB8
#define btn PB5
#define N_SENS 10


uint8_t p = 6;  // 12V
uint8_t d = 30;

uint8_t maxSpeed = 120;
uint8_t speedturn = 60;
uint8_t m1 = 45;
uint8_t m6 = 150;
uint16_t threshold = 550;

uint32_t start_time,stop_time;

int8_t line;
int8_t BLK = 1;
int8_t WHT = 0;

int8_t lineBreak;
int8_t deadEnd;
int8_t lastPosition = 0;
uint16_t bitSensor = 0;
int8_t line_position = 0;
int16_t lastError = 0;
int16_t error = 0;

uint16_t arraySensor[10];
uint8_t bar[8][8] PROGMEM = {{0, 128, 128, 128, 128, 128, 128, 0}, {0, 192, 192, 192, 192, 192, 192, 0},
  {0, 224, 224, 224, 224, 224, 224, 0}, {0, 240, 240, 240, 240, 240, 240, 0},
  {0, 248, 248, 248, 248, 248, 248, 0}, {0, 252, 252, 252, 252, 252, 252, 0},
  {0, 254, 254, 254, 254, 254, 254, 0}, {0, 255, 255, 255, 255, 255, 255, 0}
};


int16_t sensor_values[N_SENS];
int16_t sens_max[N_SENS] = { 3850,3850,3850, 3850, 3850, 3850, 3850, 3850, 3850, 3850 };
int16_t sens_min[N_SENS] = { 3300,3300, 3300, 3300, 3300, 3300, 3300, 3300, 3500,3300 };
int8_t onSensor[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
// int16_t sens_min[N_SENS] = { 2900, 2800, 2800, 2600, 2600, 2900, 3000, 2900 };

unsigned char path_length = 0;
unsigned char found_left = 0;
unsigned char found_straight = 0;
unsigned char found_right = 0;
int16_t sLR[2];

void initRobot(){
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  pinMode(led, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  pinMode(PA4, OUTPUT);
  pinMode(PA0, OUTPUT);
  pinMode(PA5, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(btn, INPUT_PULLUP);

  Wire.setSDA(PB11);
  Wire.setSCL(PB10);
  lcd.begin();
  lcd.setPowerSave(0);
  lcd.setFont(u8x8_font_chroma48medium8_r);
  lcd.clear();
}
