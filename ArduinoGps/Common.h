class TimeLogger
{
  public:
    TimeLogger(bool enabled, String name);
    void done();
  private:
    unsigned long _startTimeMs;
    String _name;
    bool _enabled;
};

void blinkN(int times, int delayMs);

class DateTime
{
  public:  
    DateTime();
    DateTime(short year, byte month, byte day,
             byte hour, byte minute, byte second);
    byte hour();
    void hour(byte val);
    byte minute();
    void minute(byte val);
    byte second();
    void second(byte val);
    short year();
    void year(short val);
    byte month();
    void month(byte val);
    byte day();
    void day(byte val);
    
    bool operator==(const DateTime &other) const;
    bool operator!=(const DateTime &other) const;
    
    String toString();
    
  private:
    short _year; byte _month; byte _day;
    byte _hour; byte _minute; byte _second;
};

class GpsData
{
  public:  
    GpsData();
    GpsData(DateTime dateTimeUtc, double lat, double lon, int alt, int hdop, int satellites);
    
    double lat();
    void lat(double val);
    
    double lon();
    void lon(double val);
    
    int alt();
    void alt(int val);
    
    int hdop();
    void hdop(int val);
    
    int satellites();
    void satellites(int val);
    
    DateTime dateTimeUtc();
    void dateTimeUtc(DateTime val);

    String toString();
    
  private:
    DateTime _dateTimeUtc;
    double _lat; 
    double _lon; 
    int _alt;
    int _hdop; 
    int _satellites;
};


