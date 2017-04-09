
#include <TinyGPS.h>

TinyGPS gpsEncoder;

void collectGpsDataCallback() 
{
  if (noInterupt) return;  
  noInterupt = true;
  interrupts();
  
  TimeLogger timeLog = TimeLogger(false, "--------GPS");
  bool isnewDataCome = false;

  // Allow serial to read at least one byte.
  while(!gpsSerial.available()){
    //Serial.println("waiting for data");
  }
  
  // reading data
  while (gpsSerial.available())
  {
    char dataChar = gpsSerial.read(); //reading symbol by simbol
    //Serial.write(dataChar); // GPS data flowing
    
    gpsEncoder.encode(dataChar);
  }

  timeLog.Done();

  noInterupt = false;
}

unsigned short totalSentences = 0;

void printGpsStats()
{  
  unsigned long chars;
  unsigned short sentences, failed;
  
  gpsEncoder.stats(&chars, &sentences, &failed);
  
  Serial.print(" CHARS=");
  Serial.print(chars);
  Serial.print(" SENTENCES=");
  Serial.print(sentences);
  Serial.print(" ERRORS=");
  Serial.println(failed);
  
  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");

    
  if (sentences != totalSentences)
  {
    totalSentences = sentences;
    
    float flat, flon;
    unsigned long age;
    gpsEncoder.f_get_position(&flat, &flon, &age);
    Serial.print("LAT=");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" LON=");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    Serial.print(" SAT=");
    Serial.print(gpsEncoder.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gpsEncoder.satellites());
    Serial.print(" PREC=");
    Serial.println(gpsEncoder.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gpsEncoder.hdop());
  }
}


