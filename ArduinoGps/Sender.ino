
void sendDataCallback() 
{   
  TimeLogger timeLog(true, "--------GPRS send");

  for(int i=0; i<500; i++)
  {
    delay(1);
  }  
  //blinkN(3);
    
  timeLog.done();
}

