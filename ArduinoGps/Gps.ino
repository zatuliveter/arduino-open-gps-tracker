#include "TinyGPS++.h"

TinyGPSPlus gpsEncoder;

void collectGpsDataCallback() 
{
  //Serial.println("collectGpsDataCallback");
  
  if (noInterrupt) {
    return;  
  } 
  else { 
    noInterrupt = true; 
    interrupts();
  }
    
  TimeLogger timeLog(false, "--------GPS");
  
  // Allow serial to read at least one byte.
  //while(!gpsSerial.available())
  //{
    //Serial.println("waiting for data");
  //}
  
  // reading data
  while (gpsSerial.available() > 0)
  {
    char dataChar = gpsSerial.read(); //reading symbol by simbol
    //Serial.write(dataChar);; // GPS data flowing
    gpsEncoder.encode(dataChar);
  }
  
  timeLog.done();

  noInterrupt = false;
}


void printGpsStats()
{ 
  TimeLogger timeLog(false, "--------GPS Stats");
    
  Serial.print("Chars=");
  Serial.print(gpsEncoder.charsProcessed());
  Serial.print(" Sentences=");
  Serial.print(gpsEncoder.sentencesWithFix());
  Serial.print(" Errors=");
  Serial.println(gpsEncoder.failedChecksum());
      
  //if (gpsEncoder.location.isUpdated())
  {  
    Serial.print("Lat=");
    Serial.print(gpsEncoder.location.lat(), 6);
    Serial.print(" Lon=");
    Serial.print(gpsEncoder.location.lng(), 6);
    Serial.print(" Sat=");
    Serial.print(gpsEncoder.satellites.value());
    Serial.print(" Prec=");
    Serial.println(gpsEncoder.hdop.value());
  }

  timeLog.done();
}


