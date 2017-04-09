
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

//DateTime class
DateTime::DateTime() {}
DateTime::DateTime( short year, byte month, byte day,
		  byte hour, byte minute, byte second) 
{
	_year = year; 
	_month = month; 
	_day = day;
  _hour = hour; 
	_minute = minute; 
	_second = second;
}    
byte DateTime::hour() { return _hour; }
void DateTime::hour(byte val) { _hour = val; }
byte DateTime::minute() { return _minute; }
void DateTime::minute(byte val) { _minute = val; }
byte DateTime::second() { return _second; }
void DateTime::second(byte val) { _second = val; }
short DateTime::year() { return _year; }
void DateTime::year(short val) { _year = val; }
byte DateTime::month() { return _month; }
void DateTime::month(byte val) { _month = val; }
byte DateTime::day() { return _day; }
void DateTime::day(byte val) { _day = val; }
bool DateTime::operator==(const DateTime &other) const {

  if (this == &other) return true;
  
  if(_second != other._second) return false;
  if(_minute != other._minute) return false;
  if(_hour != other._hour) return false;
  if(_day != other._day) return false;
  if(_month != other._month) return false;
  if(_year != other._year) return false;

  return true;
}
bool DateTime::operator!=(const DateTime &other) const {
  return !(this == &other);
}

String DateTime::toString() {
  String result = "";
  
  result += String(_year);
  result += "-" + String(_month);
  result += "-" + String(_day);
  
  result += " " +String(_hour);
  result += ":" + String(_minute);
  result += ":" + String(_second);
  
  return result;
}

// GpsData class
GpsData::GpsData() {}
GpsData::GpsData(DateTime dateTimeUtc, double lat, double lon, int alt, int hdop, int satellites) {
  _dateTimeUtc = dateTimeUtc;
  _lat = lat;
  _lon = lon;
  _alt = alt;
}

double GpsData::lat() { return _lat; }
void GpsData::lat(double val) { _lat = val; }

double GpsData::lon() { return _lon; }
void GpsData::lon(double val) { _lon = val; }

int GpsData::alt() { return _alt; }
void GpsData::alt(int val) { _alt = val; }

int GpsData::hdop() { return _hdop; }
void GpsData::hdop(int val) { _hdop = val; }

int GpsData::satellites() { return _satellites; }
void GpsData::satellites(int val) { _satellites = val; }
  
DateTime GpsData::dateTimeUtc() { return _dateTimeUtc; }
void GpsData::dateTimeUtc(DateTime val) { _dateTimeUtc = val; }

String GpsData::toString() {
  String result = "";

  result += "Time" + _dateTimeUtc.toString();
  result += " Lat=" + String(_lat, 6);
  result += " Lon=" + String(_lon, 6);
  
  result += " Sat=" + String(_satellites);
  result += " Hdop=" + String(_hdop);

  return result;
}

