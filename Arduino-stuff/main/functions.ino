

int modulo(int x, int N) {
  return (x % N + N) % N;
}


int mini(int x, int y) {
  return x <= y ? x : y;
}


void writeString(char* text) {
  char* c = text;
  while (*c) {
    display.write(*c);
    c++;
  }
}


void drawLine(int start, int stop, int thick) {
  for (int i = start; i < stop; ++i) {
    for (int j = 0; j < thick; j++) {
      display.drawPixel(i, 16 + j, WHITE);
    }
  }
}


void writeGate(bool b) {
  if (b) {
    writeString("on");
  } else {
    writeString("off");
  }
}


void lamps(){
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
}


void rotate_servo(unsigned long* StartTimer_servo, bool sev, int* servo_angle, bool* sev_av, Servo servo_pin) {
  unsigned long deltaTime = currentTime - *StartTimer_servo;
  if (deltaTime >= internalTimer_servo && sev) {
    *StartTimer_servo = currentTime;
    servo_pin.write(*servo_angle);
    *servo_angle += ANGLE_MOVE;
    if (*servo_angle >= ANGLE_ON) {
      *servo_angle = ANGLE_ON;
      *sev_av = true;
    }
  }

  if (deltaTime >= internalTimer_servo && !sev) {
    *StartTimer_servo = currentTime;
    servo_pin.write(*servo_angle);
    *servo_angle -= ANGLE_MOVE;

    if (*servo_angle <= ANGLE_OFF) {
      *servo_angle = ANGLE_OFF;
      *sev_av = true;
    }
  }
}


void gate2() {
  button1.update();
  button2.update();

  if (button1.fell() && sev1_av) {
    Serial.println("1!");
    sev1 = !sev1;
    sev1_av = false;
  }

  if (button2.fell() && sev2_av) {
    Serial.println("2!");
    sev2 = !sev2;
    sev2_av = false;
  }

  rotate_servo(&StartTimer_servo1, sev1, &servo_angle1, &sev1_av, servo_pin_2);
  rotate_servo(&StartTimer_servo2, sev2, &servo_angle2, &sev2_av, servo_pin_3);


  display.clearDisplay();
  display.setCursor(0, 0);

  writeString("Gate 1:");
  writeGate(sev1);
  drawLine(0, SCREEN_WIDTH, 1);
  display.setCursor(0, 18);
  writeString("Gate 2:");
  writeGate(sev2);

  display.display();
}


void gate3() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    Serial.println("1!");
    --state;
  }

  if (button2.fell()) {
    Serial.println("2!");
    ++state;
  }

  state = modulo(state, 3);

  display.clearDisplay();
  display.setCursor(0, 0);
  switch (state) {
    case 0:
      writeString("LEFT");
      drawLine(0, SCREEN_WIDTH / 3, 3);
			sev1 = false;
			sev2 = false;
      break;
    case 1:
      writeString("MIDDLE");
      drawLine(SCREEN_WIDTH / 3, (SCREEN_WIDTH * 2) / 3, 3);
			sev1 = false;
			sev2 = true;
      break;
    case 2:
      writeString("RIGHT");
      drawLine((SCREEN_WIDTH * 2) / 3, SCREEN_WIDTH, 3);
			sev1 = true;
			sev2 = true;
      break;
  }

  rotate_servo(&StartTimer_servo1, sev1, &servo_angle1, &sev1_av, servo_pin_2);
  rotate_servo(&StartTimer_servo2, sev2, &servo_angle2, &sev2_av, servo_pin_3);

  display.display();
}
