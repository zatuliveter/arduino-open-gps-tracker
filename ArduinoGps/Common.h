class TimeLogger
{
  public:
    TimeLogger(bool enabled, char* name);
    //unsigned long ElapsedMs();
    void Done();
  private:
    unsigned long _startTimeMs;
    char* _name;
    bool _enabled;
};

void blinkN(int times);

