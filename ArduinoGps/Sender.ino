
void sendDataCallback() 
{   
  TimeLogger timeLog = TimeLogger(true, "--------GPRS send");

  for(int i=0; i<5000; i++)
  {
    delay(1);
  }  
  //blinkN(3);
    
  timeLog.Done();  
}

