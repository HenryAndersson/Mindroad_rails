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

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int modulo(int x, int N) {
  return (x % N + N) % N;
}

void writeString(char* text) {
  char* c = text;
  while (*c) {
    display.write(*c);
    c++;
  }
}

void drawLine(int start, int stop) {
  for (int i = start; i < stop; ++i) {
    display.drawPixel(i, 17, WHITE);
    display.drawPixel(i, 18, WHITE);
    display.drawPixel(i, 19, WHITE);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(5, INPUT_PULLUP);
  button1.attach(5);
  button1.interval(10);

  pinMode(4, INPUT_PULLUP);
  button2.attach(4);
  button2.interval(10);


  servo_pin_2.attach(2, 530, 2600);
  servo_pin_2.write(0);

  servo_pin_3.attach(3, 530, 2600);
  servo_pin_3.write(0);
  delay(2000);



  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }


  display.clearDisplay();
  display.display();
  display.setTextSize(2);       // Normal 1:1 pixel scale
  display.setTextColor(WHITE);  // Draw white text
  display.setCursor(0, 0);      // Start at top-left corner
  display.cp437(true);


  Serial.println("Klar!");
}

bool sev1 = false;
bool sev2 = false;
int state = 1;

void loop() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    Serial.println("1!");
    --state;
    sev1 = !sev1;
    if (sev1) {
      servo_pin_2.write(40);
    } else {
      servo_pin_2.write(0);
    }

    delay(100);
  }

  if (button2.fell()) {
    Serial.println("2!");
    ++state;
    sev2 = !sev2;
    if (sev2) {
      servo_pin_3.write(40);
    } else {
      servo_pin_3.write(0);
    }

    delay(100);
  }

  state = modulo(state, 3);
  display.clearDisplay();
  display.setCursor(0, 0);

  switch (state) {
    case 0:
      writeString("LEFT");
			drawLine(0, SCREEN_WIDTH / 3);
      break;
    case 1:
      writeString("MIDDLE");
			drawLine(SCREEN_WIDTH / 3, (SCREEN_WIDTH * 2) / 3);
      break;
    case 2:
      writeString("RIGHT");
			drawLine((SCREEN_WIDTH * 2)  / 3, SCREEN_WIDTH);
      break;
  }

  display.display();
  Serial.println(state);
}
