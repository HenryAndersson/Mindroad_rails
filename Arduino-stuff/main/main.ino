#include <Thread.h>
#include <Servo.h>
#include <Bounce2.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Servo servo_pin_2;
Servo servo_pin_3;

Bounce button1 = Bounce();
Bounce button2 = Bounce();

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET 4

#define LED1 7
#define LED2 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


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
  updateServo(true, 0, 70);

  digitalWrite(LED1, LOW);
}

bool sev1 = false;
bool sev2 = false;
int state = 1;

unsigned long timer_led1 = 0;
unsigned long timer_led2 = 0;

unsigned long interval_led = 10;

void loop() {
  unsigned long currentTime = millis();

  //digitalWrite(LED2, LOW);
  //delay(100);
  //digitalWrite(LED1, LOW);
  //digitalWrite(LED2, HIGH);
  //delay(100);

#if 1
  if (digitalRead(6) == HIGH) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(5) == HIGH) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
#else
  gate3();
#endif
}
