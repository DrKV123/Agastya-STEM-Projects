
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>




float accx, accy, accz;
float total;
String nodeReds;
char Buf[200];
int rows;
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup(void) {

  Serial.begin(9600);
  accSetup();


  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");

  setupTFT ();


}

void loop() {

  sensors_event_t event;
  lis.getEvent(&event);

  accx = - event.acceleration.x;
  accy = - event.acceleration.y;
  accz = - event.acceleration.z;
  
  if (rows % 4 == 0) {  delay (500); TFTPrintHeader(); rows = 0;}

  rows++;

  serialPrint();
  //TFT print
  TFTPrintString((String)accx + "  " + (String) accy + "  " + (String) accz);
  
  delay (500);
}
