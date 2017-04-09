#include "Common.h"
#include <Thread.h>
#include <SoftwareSerial.h>


Thread sendDataThread;
Thread gpsStatsThread;
SoftwareSerial gpsSerial(3/*rx*/, 4/*tx*/);
bool noInterupt = false;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  
  // config send by gprs network thread
  sendDataThread.onRun(sendDataCallback);
  sendDataThread.setInterval(1000);

  // config gps thread
  gpsStatsThread.onRun(printGpsStats);
  gpsStatsThread.setInterval(3000);

  // interrupt 1 - digital input 3 for arduino uno
  attachInterrupt(1, collectGpsDataCallback, RISING );
  
}

void loop() {
  // Main Loop
    
  if(sendDataThread.shouldRun()) sendDataThread.run();
 
  if(gpsStatsThread.shouldRun()) gpsStatsThread.run();

  //collectGpsDataCallback();

}


