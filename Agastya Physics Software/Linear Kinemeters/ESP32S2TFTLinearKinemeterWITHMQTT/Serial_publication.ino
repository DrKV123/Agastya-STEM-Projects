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
    Serial.println((String)instTime[j]+"\t"+(String)pos);
    //if (j < sensors - 1)Serial.print(", ");
  }
  Serial.println();
}
void printTimeVel()
{
  Serial.println("\t\tTime(s)\t\t\t\tVelocity(cm/s):");
  for (int j = 1; j < sensors; j++)
  {
    Serial.print("Pos"+(String)j+" to Pos"+(String)(j+1)+":\t");
    Serial.println((String)AvgTime[1]+"\t\t\t\t"+(String)speedArray[j]);
    //if (j < sensors - 1)Serial.print(", ");
  }
  Serial.println();
}
void printAccel()
{
  Serial.println("\t\tAcceleration(cm/s/s):");
  for (int j = 1; j < sensors-1; j++)
  {
    Serial.print("Vel"+(String)j+" to Vel"+(String)(j+1)+":\t");
    Serial.println(accl[j]);
    //if (j < sensors - 1)Serial.print(", ");
  }
  Serial.println("Average Acceleration: " + (String)avgAcc);
}
void printSelfConfig()
{
  Serial.println (model);
  Serial.print("Number of Sensors ="); Serial.println(sensors);
  printPinArray();
  //printdispArray();
  Serial.println();
}
/*
void serialPrintVelocities()
{
  Serial.println();
  Serial.print("----"); Serial.print("\t"); Serial.print("Instantaneous Velocities At MID POINTS");  Serial.print("\t"); Serial.println("----");
  for (int pinArrayindex = 0; pinArrayindex < sensors; pinArrayindex++)
  {

    if (pinArrayindex > 0)
    {

      Serial.print(F("           Inst Velocity at midpoint (aka avg. betw.) sensors  S"));
      Serial.print(pinArrayindex); Serial.print(" and S"); Serial.print(pinArrayindex + 1);
      Serial.print(" (Pins ");
      Serial.print(pinArray[pinArrayindex - 1]); Serial.print(" and "); Serial.print(pinArray[pinArrayindex]);
      Serial.print(" )");
      Serial.print(" is ");
      Serial.print(speedArray[pinArrayindex], 4); Serial.print("cm/sec ");
      Serial.print(" at T=  "); Serial.print(AvgTime[pinArrayindex], 4); Serial.println("sec");
    }

  }
}

void serialPrintPositions()
{
  Serial.println();
  Serial.print("----"); Serial.print("\t"); Serial.print("POSITIONS Crossing Sensors");  Serial.print("\t"); Serial.println("----");
  for (int pinArrayindex = 0; pinArrayindex < sensors; pinArrayindex++)
  {
    Serial.print("Crossed Sensor S"); Serial.print (pinArrayindex + 1);
    Serial.print("(Pin #"); Serial.print(pinArray[pinArrayindex]); Serial.print(")"); Serial.print("  at T= ");
    Serial.println(instTime[pinArrayindex], 4);

  }

}

void SerialPrintAccelerations()

{

  Serial.println();
  Serial.print("----"); Serial.print("\t"); Serial.print("ACCELERATIONS between Mid points ");  Serial.print("\t"); Serial.println("----");
  for (int j = 1; j < sensors - 1; j++)
  {

    Serial.print(F(" Acc.betw mid-pt of Sensors: S"));
    Serial.print(j); Serial.print("&"); Serial.print(" S"); Serial.print(j + 1); Serial.print(" (Pins "); Serial.print(pinArray[j - 1]); Serial.print("&"); Serial.print(pinArray[j]); Serial.print(") ");
    Serial.print (" and mid-pt-of "); Serial.print(F("  Sensors: S"));
    Serial.print(j + 1); Serial.print("&"); Serial.print(" S"); Serial.print(j + 2); Serial.print(" (Pins "); Serial.print(pinArray[j]); Serial.print("&"); Serial.print(pinArray[j + 1]); Serial.print(") ");
    Serial.print(" is:   "); Serial.print(accl[j], 4); Serial.println (" cm/sec^2");
  }

  Serial.println();
  Serial.print("----"); Serial.print("\t"); Serial.print("AVERAGE ACC");  Serial.print("\t"); Serial.println("----");
  Serial.print (F("                      Average Acc =  "));
  //Serial.print(accSum / (sensors - 2), 4);
  Serial.print(avgAcc, 4);
  Serial.println (F(" cm/sec^2"));

}

void SerialPrint()

{

  serialPrintPositions();
  if ( printVel)  serialPrintVelocities();
  if (printAcc)  SerialPrintAccelerations();
}*/
