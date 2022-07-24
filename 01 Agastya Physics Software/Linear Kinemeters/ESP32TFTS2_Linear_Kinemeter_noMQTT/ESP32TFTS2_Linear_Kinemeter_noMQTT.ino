
int neopin = 5;


String model = "ESP32 TFT S2 model no MQTT";

int tempdelay = 1000;

int const sensors = 4;
int const slots = 2 * sensors;
int pinArray [sensors] = { 12, 11, 10, 9}; //, 5,4,3};

int buttonCount = 0;
unsigned long brokenTime[sensors];
float AvgTime[sensors];
float instTime[sensors];
float accl[sensors];

boolean printVel = true;
boolean printAcc = true;
int expnumber = 0;

boolean passArray[sensors];
int sensStateArray[sensors];
int lastStateArray[sensors];
unsigned long timeArray[slots];
float deltaArray[sensors];
//const float DIST = 5.0;
float disp[sensors] = {0, 5, 10, 10};
float speedArray[sensors];
float accArray[sensors];

unsigned long curTime;
unsigned long startTime;
//float speed1;

float accSum = 0.0;
float avgAcc = 0.0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(neopin, OUTPUT);
  // initialize the sensor pin as an input:
  for (int j1 = 0; j1 < sensors; j1++)
  {
    if (pinArray[j1] == 0) {
      pinMode(pinArray[j1], INPUT);
      digitalWrite(pinArray[j1], HIGH); // turn on the pullup
    }
    else {
      pinMode(pinArray[j1], INPUT_PULLUP);
    }
    passArray[j1] = false;
  }
  Serial.begin(115200);

  setupTFT();

  Serial.println(F("Set up Complete."));

  delay(2000);
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
  delay(2000);
}




boolean allDone() //all sensors have passed through
{
  boolean output = true;

  for (int j2 = 0; j2 < sensors; j2++)
  {
    if (passArray[j2] == false) {
      output = false; // if even one is false, the total result is false.
    }
  }
  return output;
}





void resetAllDone()
{
  for (int j1 = 0; j1 < sensors; j1++)
  {
    passArray[j1] = false;
  }
}



void loop() {

  for (int x = 0; x < sensors; x++)
  {
    processSensorPinat (x);
  }

  if  (allDone())
  {
    Serial.println("----");
    expnumber = expnumber + 1; Serial.print("Exp number ="); Serial.println(expnumber);
    if (expnumber == 2) {
      printSelfConfig();
    };
    processAcc();

    String s = "";

    printTimePos();
    tftPrintTimePos();

    printTimeVel();
    tftPrintTimeVel();

    printAccel();
    tftPrintAccel();

    printCompileFileAndDate();
    printSelfConfig();

    resetAllDone();
  }

}
