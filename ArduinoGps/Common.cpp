
#include <Arduino.h>
#include "Common.h"

TimeLogger::TimeLogger(bool enabled, String name)
{
  _startTimeMs = millis();
  _name = name;
  _enabled = enabled;
  
  if(_enabled) Serial.println(_name);
}
void TimeLogger::done()
{
  if(_enabled) {
    Serial.print(_name);
  
    Serial.print(": elapsed ");
    unsigned long elapsedMs = millis() - _startTimeMs;
    Serial.print(elapsedMs);  
    Serial.println(" ms.");
  }
}

void blinkN(int times, int delayMs) 
{
  for(int i=0; i<times; i++)
  {
    digitalWrite(13, true);
    for(int i=1; i<delayMs; i++) delay(1);
    digitalWrite(13, false);
    for(int i=1; i<delayMs; i++) delay(1);    
  }  
}


