
#include <Arduino.h>
#include "Common.h"

TimeLogger::TimeLogger(bool enabled, char* name)
{
  _startTimeMs = millis();
  _name = name;
  _enabled = enabled;
  
  if(_enabled) Serial.println(_name);
  //Serial.println(F(" time logger starting"));  
}
void TimeLogger::Done()
{
  if(_enabled) {
    Serial.print(_name);
  
    Serial.print(": elapsed ");
    unsigned long elapsedMs = millis() - _startTimeMs;
    Serial.print(elapsedMs);  
    Serial.println(" ms.");
  }
}
/*
unsigned long TimeLogger::ElapsedMs()
{
  unsigned long elapsedMs = millis() - _startTimeMs;
  return elapsedMs;
}
*/

void blinkN(int times) 
{
  for(int i=0; i<times; i++)
  {
    digitalWrite(13, true);
    delay(250);
    digitalWrite(13, false);
    delay(250); 
  }  
}


