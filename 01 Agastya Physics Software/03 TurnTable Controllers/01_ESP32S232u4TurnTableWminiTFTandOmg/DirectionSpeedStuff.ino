void controlSpeedDirection() {
  uint32_t buttons = ss.readButtons();

  uint16_t color;
  color = ST77XX_WHITE;
  tft.setCursor(0, 50);
  tft.print("Speed: "); tft.print(motorSpeed);
  //  TFTPrintOmega();


  analogWrite(pwm, motorSpeed);

  color = ST77XX_BLACK;

  //direction action 1
  if (! (buttons & TFTWING_BUTTON_RIGHT)) {
    CCW();
    tft.fillScreen(ST77XX_BLACK);
    Serial.println("COUNTERCLOCKWISE");
    //    color = ST77XX_WHITE;
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(0, 80);
    tft.print("CCW");
    tft.setTextColor(ST77XX_WHITE);

  }
  //direction action 2

  if (! (buttons & TFTWING_BUTTON_LEFT)) {
    CW();
    tft.fillScreen(ST77XX_BLACK);
    Serial.println("CLOCKWISE");
    //color = ST77XX_WHITE;
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(0, 80);
    tft.print("CW");
    tft.setTextColor(ST77XX_WHITE);
  }


  color = ST77XX_BLACK; // see if you can optimize the blacks  do we even need it.



  //Speed action 3
  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_DOWN)) {
    tft.fillScreen(ST77XX_BLACK);
    Serial.println("SLOW DOWN");
    motorSpeed -= 5;
    if (motorSpeed < 0) {
      motorSpeed = 0;
    }
    Serial.print("Speed: "); Serial.println(motorSpeed);
    color = ST77XX_WHITE;
    tft.fillScreen(ST77XX_BLACK);
  }


  tft.setCursor(0, 50);
  tft.print("Speed: "); tft.print(motorSpeed);

  //Speed action 4
  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_UP)) {

    Serial.println("SPEED UP");
    motorSpeed += 5;
    if (motorSpeed > 255) {
      motorSpeed = 255;
    }

    Serial.print("Speed: "); Serial.println(motorSpeed);
    color = ST77XX_WHITE;
    tft.fillScreen(ST77XX_BLACK);
  }


  tft.setCursor(0, 50);
  tft.print("Speed: "); tft.print(motorSpeed);



  color = ST77XX_BLACK;
  //Stop action 5
  if (! (buttons & TFTWING_BUTTON_SELECT)) {
    tft.fillScreen(ST77XX_BLACK);
    Serial.println("STOP");
    motorSpeed = 0;
    Serial.print("Speed: "); Serial.println(motorSpeed);
    color = ST77XX_WHITE;
    //fSTOP();
  }


}

void TFTPrintOmega(uint16_t color)
{
  //  uint16_t color;
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(color);
  tft.setCursor(0, 20);
  tft.print("Omega: "); tft.print(omega);
  tft.setTextColor(ST77XX_WHITE);
}

void TFTPrintCount()
{
  uint16_t color;
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(40, 80);
  tft.print("Count:"); tft.print(crossCount);
  tft.setTextColor(ST77XX_WHITE);
}

void TFTCountandOMEGA(uint16_t color)
{
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(color);
  tft.setCursor(0, 20);
  tft.print("Omega: "); tft.print(omega);
  tft.setCursor(40, 80);
  tft.print("Count:"); tft.print(crossCount);
  tft.setTextColor(ST77XX_WHITE);
}
