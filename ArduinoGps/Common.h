class TimeLogger
{
  public:
    TimeLogger(bool enabled, String name);
    //unsigned long ElapsedMs();
    void Done();
  private:
    unsigned long _startTimeMs;
    String _name;
    bool _enabled;
};

void blinkN(int times);

