
#include <Wire.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setupTFT ()
{
  Serial.print(F("Hello! Feather TFT Test"));

  // turn on backlite
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);

  // turn on the TFT / I2C power supply
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);

  // initialize TFT
  tft.init(135, 240); // Init ST7789 240x135
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);

  Serial.println(F("Initialized"));

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;
  tft.print("Ready...");
  Serial.println(time, DEC);
  delay(500);

}


void setNextLine()
{
  tft.setCursor(0, tft.getCursorY() + 25);
}
 
void TFTPrintString(String xyz)
{
  tft.setTextSize(2);
  tft.print(xyz);
  setNextLine();
}

void TFTPrintHeader()
{
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(0, 0);
  TFTPrintString(" X     Y     Z m/s^2");
  tft.setTextColor(ST77XX_WHITE);
}
