/*
    lab7clock.h
    William Fraser 30158991
*/

#ifndef lab7clock_h
#define lab7clock_h

class Clock{
public:
    Clock();
    Clock(int seconds);
    Clock(int hours, int minutes, int seconds);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    void set_hour(int hours);
    void set_minute(int minutes);
    void set_second(int seconds);
    void increment();
    void decrement();
    void add_seconds(int seconds_to_add);

private:
    int hour, minute, second;
    int hms_to_sec();
    void sec_to_hms(int seconds);
};

#endif