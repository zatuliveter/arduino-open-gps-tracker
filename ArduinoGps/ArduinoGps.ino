#include <TinyGPS++.h>
#include <Thread.h>
#include <SoftwareSerial.h>
#include "Common.h"

Thread sendDataThread;
Thread gpsStatsThread;
Thread blinkThread;
SoftwareSerial gpsSerial(2/*rx*/, 4/*tx*/);
volatile bool noInterrupt = false;
bool blinkStatus = false;

void setup() {
  gpsSerial.begin(9600);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  // config send by gprs network thread
  sendDataThread.onRun(sendDataCallback);
  sendDataThread.setInterval(5000);

  // config gps thread
  gpsStatsThread.onRun(printGpsStats);
  gpsStatsThread.setInterval(3000);
  
  // config gps thread
  blinkThread.onRun(blinkCallback);
  blinkThread.setInterval(500);

  // interrupt 0 - digital input 2 for arduino uno
  attachInterrupt(0, collectGpsDataCallback, CHANGE);
}

void loop() {
  // Main Loop
    
  if(sendDataThread.shouldRun()) sendDataThread.run(); 
  if(gpsStatsThread.shouldRun()) gpsStatsThread.run();
  if(blinkThread.shouldRun()) blinkThread.run();  

  //collectGpsDataCallback();
}

void blinkCallback()
{
  blinkStatus = !blinkStatus;
  digitalWrite(13, blinkStatus);
}

