void printPinArray()
{
  Serial.print("Sensor Pins:");
  for (int j = 0; j < sensors; j++)
  {
    Serial.print(pinArray[j]);
    if (j < sensors - 1)Serial.print(", ");
  }
  Serial.println();
}

void printTimePos()
{
  float pos = 0.0;
  Serial.println("Time(s)\tPosition(cm):");
  for (int j = 0; j < sensors; j++)
  {
    pos += disp[j];
    Serial.println((String)instTime[j] + "\t" + (String)pos);

  }
  Serial.println();
}
void printTimeVel()
{
  Serial.println("\t\tTime(s)\t\t\t\tVelocity(cm/s):");
  for (int j = 1; j < sensors; j++)
  {
    Serial.print("Pos" + (String)j + " to Pos" + (String)(j + 1) + ":\t");
    Serial.println((String)AvgTime[1] + "\t\t\t\t" + (String)speedArray[j]);

  }
  Serial.println();
}
void printAccel()
{
  Serial.println("\t\tAcceleration(cm/s/s):");
  for (int j = 1; j < sensors - 1; j++)
  {
    Serial.print("Vel" + (String)j + " to Vel" + (String)(j + 1) + ":\t");
    Serial.println(accl[j]);
    //if (j < sensors - 1)Serial.print(", ");
  }
  Serial.println("Average Acceleration: " + (String)avgAcc);
}

void printCompileFileAndDate()
{

  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
}

void printSelfConfig()
{
  Serial.println (model);
  Serial.print("Number of Sensors ="); Serial.println(sensors);
  printPinArray();
  Serial.println();
}
