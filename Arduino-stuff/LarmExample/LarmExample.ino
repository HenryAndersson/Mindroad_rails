int modulo(int x,int N){
    return (x % N + N) %N;
}

#include <Servo.h>
#include <Bounce2.h>

Servo servo_pin_2;
Servo servo_pin_3;

Bounce button1 = Bounce();
Bounce button2 = Bounce();

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

  Serial.println("Klar!");
}

bool sev1 = false;
bool sev2 = false;
int state = 1;

void loop() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    //Serial.println("1!");
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
    //Serial.println("2!");
    ++state;
    sev2 = !sev2;
    if (sev2) {
      servo_pin_3.write(40);
    } else {
      servo_pin_3.write(0);
    }

    delay(100);
  }

  state = modulo(state,3);
  Serial.println(state);
}