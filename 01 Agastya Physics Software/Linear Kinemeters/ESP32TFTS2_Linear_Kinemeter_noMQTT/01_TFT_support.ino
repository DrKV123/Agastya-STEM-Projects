

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

  Serial.println(time, DEC);
  delay(500);
  //client.setServer(mqtt_server, 1883);
}

void printTFT (String s1)
{
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(0, 0);
  tft.setTextWrap(true);
  tft.setTextSize(3);
  tft.print(s1);
}

void tftPrintTimePos(){
  float pos = 0.0;
  printTFT("Time(s)  Position(cm):");
  for (int j = 0; j < sensors; j++)
  {
    delay(tempdelay);
    pos += disp[j];
    printTFT((String)instTime[j]+"  "+(String)pos);
  }
}

void tftPrintTimeVel(){
  printTFT("Time(s)   Velocity(cm/s):");
  for (int j = 1; j < sensors; j++)
  {
    delay(tempdelay);
    printTFT("Pos"+(String)j+" to Pos"+(String)(j+1)+": " + (String)AvgTime[1]+"   "+(String)speedArray[j]);
    //if (j < sensors - 1)Serial.print(", ");
  }
}

void tftPrintAccel()
{
  printTFT("Acceleration(cm/s/s):");
  for (int j = 1; j < sensors-1; j++)
  {
    delay(tempdelay);
    printTFT("Vel"+(String)j+" to Vel"+(String)(j+1)+": " + accl[j]);
    //if (j < sensors - 1)Serial.print(", ");
  }
  delay(tempdelay);
  printTFT("Average Acceleration: " + (String)avgAcc);
}
