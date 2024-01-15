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
#define N_SENS 8

//uint8_t p = 12; // 7.8V
//uint8_t = 120;

uint8_t p = 6;  // 7.8V
uint8_t d = 30;

uint8_t LMaxSpeed = 120;
uint8_t RMaxSpeed = 130;
uint8_t speedturn = 60;
uint8_t m1 = 50;
uint8_t m6 = 140;
uint16_t threshold = 500;

uint32_t start_time, stop_time, t2, t1, t3;

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
int lastTime = 0;

unsigned char found_left;
unsigned char found_straight;
unsigned char found_right;

unsigned char found_cross;


int16_t sensor_values[N_SENS];
// int16_t sens_max[N_SENS] = { 3750, 3750, 3750, 3750, 3750, 3750, 3750, 3750 };
// int16_t sens_min[N_SENS] = { 2850, 3050, 2850, 2550, 2500, 2900, 2900, 3000 };
//unsigned char sensor[N_SENS] = { PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0 };
char path[100] = "";
char reverse_path[100] = "";
unsigned char dir;
unsigned char path_length = 0;
int16_t timerSensor[2];
int16_t sens_max[N_SENS] = { 3850, 3850, 3850, 3850, 3850, 3850, 3850, 3850 };
int16_t sens_min[N_SENS] = { 3300, 3300, 3250, 3250, 3220, 3300, 3350, 3500 };

//int16_t sens_max[N_SENS] = { 3850, 3850, 3850, 3850, 3850, 3850, 3850, 3850 };
//int16_t sens_min[N_SENS] = { 2700, 2900, 2900, 2500, 2400, 2900, 2900, 2950 };
