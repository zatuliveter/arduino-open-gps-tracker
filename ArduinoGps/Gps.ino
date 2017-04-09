#include "TinyGPS++.h"

TinyGPSPlus gps;

void collectGpsDataCallback() 
{      
  // reading data
  while (gpsSerial.available() > 0)
  {
    char dataChar = gpsSerial.read(); //reading symbol by simbol
    //Serial.write(dataChar);; // GPS data flowing
    gps.encode(dataChar);
  }
}


void printGpsStats()
{ 
  TimeLogger timeLog(false, "--------GPS Stats");
   
  Serial.print("Chars=");
  Serial.print(gps.charsProcessed());
  Serial.print(" Sentences=");
  Serial.print(gps.sentencesWithFix());
  Serial.print(" Errors=");
  Serial.println(gps.failedChecksum());

  DateTime currentPositionTime(
            gps.date.year(), gps.date.month(), gps.date.day(), 
            gps.time.hour(), gps.time.minute(), gps.time.second());
  
  if (lastPositon.dateTimeUtc() != currentPositionTime)
  {  
    lastPositon.dateTimeUtc(currentPositionTime);
    lastPositon.lat(gps.location.lat());
    lastPositon.lon(gps.location.lng());
    lastPositon.alt(gps.altitude.meters());  
    lastPositon.hdop(gps.hdop.value());  
    lastPositon.satellites(gps.satellites.value());    
  }

  Serial.println(gps.location.lng());
  Serial.println(lastPositon.toString());
  timeLog.done();
}


