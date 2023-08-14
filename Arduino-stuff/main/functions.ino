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

void updateServo(bool has_updated, int rotate1, int rotate2) {
	if (has_updated){
		servo_pin_2.write(rotate1);
		servo_pin_3.write(rotate2);
	}
}

void rotate_servo1(){
  if (currentTime - StartTimer_servo1 >= internalTimer_servo && sev1) {
    StartTimer_servo1 = currentTime;
    servo_pin_2.write(servo_angle1);
    servo_angle1 += 7;
    if (servo_angle1 >= 70) {
      servo_angle1 = 70;
      sev1_av = true;
    }
  }

  if (currentTime - StartTimer_servo1 >= internalTimer_servo && !sev1) {
    StartTimer_servo1 = currentTime;
    servo_pin_2.write(servo_angle1);
    servo_angle1 -= 7;
    if (servo_angle1 <= 0) {
      servo_angle1 = 0;
      sev1_av = true;
    }
  }
}

void rotate_servo2(){
  if (currentTime - StartTimer_servo2 >= internalTimer_servo && sev2) {
    StartTimer_servo2 = currentTime;
    servo_pin_3.write(servo_angle2);
    servo_angle2 += 7;
    if (servo_angle2 >= 70) {
      servo_angle2 = 70;
      sev2_av = true;
    }
  }

  if (currentTime - StartTimer_servo2 >= internalTimer_servo && !sev2) {
    StartTimer_servo2 = currentTime;
    servo_pin_3.write(servo_angle2);
    servo_angle2 -= 7;
    if (servo_angle2 <= 0) {
      servo_angle2 = 0;
      sev2_av = true;
    }
  }
}


void gate2() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    Serial.println("1!");
    sev1 = !sev1;
		sev1_av = false;
  }

  if (button2.fell()) {
    Serial.println("2!");
    sev2 = !sev2;
		sev2_av = false;
  }

	rotate_servo2();
	rotate_servo1();

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
  has_updated = false;
  button1.update();
  button2.update();

  if (button1.fell()) {
    Serial.println("1!");
    --state;
    has_updated = true;
  }

  if (button2.fell()) {
    has_updated = true;
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
      updateServo(has_updated, 0, 0);
      break;
    case 1:
      writeString("MIDDLE");
      drawLine(SCREEN_WIDTH / 3, (SCREEN_WIDTH * 2) / 3, 3);
				updateServo(has_updated, 0, 70);
      break;
    case 2:
      writeString("RIGHT");
      drawLine((SCREEN_WIDTH * 2) / 3, SCREEN_WIDTH, 3);
      updateServo(has_updated, 70, 70);
      break;
  }

  display.display();
}
