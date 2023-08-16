#include <Servo.h>
#include <Bounce2.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define ANGLE_ON 70
#define ANGLE_OFF 0

#define ANGLE_MOVE 3 //degres
#define internalTimer_servo 30  //millisecond

#define OLED_RESET 4

#define LED1 7
#define LED2 8

Bounce button1 = Bounce();
Bounce button2 = Bounce();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//första servon
Servo servo_pin_2;
bool sev1 = false;
bool sev1_av = true;
int servo_angle1 = 0;
unsigned long StartTimer_servo1 = 0;

//andra servon
Servo servo_pin_3;
bool sev2 = false;
bool sev2_av = true;
int servo_angle2 = 0;
unsigned long StartTimer_servo2 = 0;

//globala variabler
unsigned long currentTime = -1;
int state = 1; //bara för gate3


void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(5, INPUT_PULLUP);

  button1.attach(5);
  button1.interval(10);

  pinMode(6, INPUT_PULLUP);
  button2.attach(6);
  button2.interval(10);


  pinMode(2, OUTPUT);
  servo_pin_2.attach(2, 530, 2600);
  //servo_pin_2.write(0);

  pinMode(3, OUTPUT);
  servo_pin_3.attach(3, 530, 2600);
  //servo_pin_3.write(0);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    //for (;;)
    // ;  // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.cp437(true);
  Serial.println("Klar!");
}


void loop() {
  currentTime = millis();
	lamps();
#if 0
  gate3();
#else
  gate2();
#endif
}
