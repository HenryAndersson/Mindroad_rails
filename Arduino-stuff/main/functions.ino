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

void gate2() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    Serial.println("1!");
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
    sev2 = !sev2;
    if (sev2) {
      servo_pin_3.write(40);
    } else {
      servo_pin_3.write(0);
    }
    delay(100);
  }

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
    delay(100);
  }

  if (button2.fell()) {
    Serial.println("2!");
    ++state;
    delay(100);
  }

  state = modulo(state, 3);

  display.clearDisplay();
  display.setCursor(0, 0);
  switch (state) {
    case 0:
      writeString("LEFT");
      drawLine(0, SCREEN_WIDTH / 3, 3);
      break;
    case 1:
      writeString("MIDDLE");
      drawLine(SCREEN_WIDTH / 3, (SCREEN_WIDTH * 2) / 3, 3);
      break;
    case 2:
      writeString("RIGHT");
      drawLine((SCREEN_WIDTH * 2) / 3, SCREEN_WIDTH, 3);
      break;
  }

  display.display();
}
