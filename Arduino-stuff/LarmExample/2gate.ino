void gate2(){
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
  Serial.println(state);
};
