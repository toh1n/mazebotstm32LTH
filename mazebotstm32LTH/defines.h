//Developed by tohin github:@toh1n email: tohin214@gmail.com
#define rightMotorForward PA8
#define rightMotorBackward PB15
#define rightMotorPWM PA9
#define leftMotorForward PB12
#define leftMotorBackward PB13
#define leftMotorPWM PB1

#define led PC13
#define buzzer PB7
#define btn PB10
#define N_SENS 8

//uint8_t p = 12; // 7.8V
//uint8_t = 120;

uint8_t p = 20;  // 7.8V
uint8_t d = 200;

uint8_t maxSpeed = 200;
uint8_t speedturn = 80;
uint8_t m1 = 75;
uint8_t m6 = 150;
uint16_t threshold = 600;

int8_t lineBreak;
int8_t deadEnd;
int8_t lastPosition = 0;
uint16_t bitSensor = 0;
int8_t line_position = 0;
int16_t lastError = 0;
int16_t error = 0;

int16_t sensor_values[N_SENS];
int16_t sens_max[N_SENS] = { 3850, 3850, 3850, 3850, 3850, 3850, 3850, 3850 };
int16_t sens_min[N_SENS] = { 3400, 3350, 3320, 3330, 3440, 3350, 3400, 3600 };
unsigned char sensor[N_SENS] = { PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0 };
char path[100] = "";
char reverse_path[100] = "";
unsigned char dir;
unsigned char path_length = 0;

//int16_t sens_max[N_SENS] = { 3850, 3850, 3850, 3850, 3850, 3850, 3850, 3850 };
//int16_t sens_min[N_SENS] = { 2700, 2900, 2900, 2500, 2400, 2900, 2900, 2950 };
