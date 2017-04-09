#include <TinyGPS++.h>
#include <Thread.h>
#include <SoftwareSerial.h>
#include "Common.h"

Thread sendDataThread;
Thread gpsStatsThread;
Thread blinkThread;
SoftwareSerial gpsSerial(3/*rx*/, 4/*tx*/);
volatile bool noInterrupt = false;
bool blinkStatus = false;
GpsData lastPositon = GpsData();

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

  // interrupt 1 - digital input 3 for arduino uno
  //TODO: Check it: Looks like we cannot use interrupts togeter with SoftSerial, it hangs at some point of time
  attachInterrupt(1, collectGpsDataCallback, CHANGE);
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

