#include <Servo.h>
#include <Bounce2.h>

Servo servo_pin_2;
Bounce button1 = Bounce();
Bounce button2 = Bounce();

void setup() {
  button1.attach(4);
  button1.interval(10);

  button2.attach(5);
  button2.interval(10);


  servo_pin_2.attach(2, 530, 2600);
  servo_pin_2.write(0);
  delay(2000);

  Serial.println("Klar!");
}
void loop() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    servo_pin_2.write(90);
    delay(300);
  }

  if (button2.fell()) {
    servo_pin_2.write(0);
    delay(300);
  }
}