/*
    lab7clock.cpp
    William Fraser 30158991
*/

#include "lab7clock.h"

Clock::Clock()  //default constructor: initializes members to 0
{
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::Clock(int seconds)   //constructor if seconds are given as arg
{
    if(seconds < 0)     //initializes to 0 if negative seconds are given
        seconds = 0;
    sec_to_hms(seconds);    //uses helper function to initialize each member
}

//constructor given all member values as arguments
Clock::Clock(int hours, int minutes, int seconds)
{
    //initializes member values to 0 based on given conditions
    if((hours >= 24 || hours < 0) || (minutes >= 60 || minutes < 0) 
    || (seconds >= 60 || seconds < 0)){
        hour = 0;
        minute = 0;
        second = 0;
    }
        
    else{   //initializes members if the inputs are acceptable
        hour = hours;
        minute = minutes;
        second = seconds;
    }
}

int Clock::get_hour()const
{
    return hour;
}

int Clock::get_minute()const
{
    return minute;
}

int Clock::get_second()const
{
    return second;
}

void Clock::set_hour(int hours)
{   
    //sets hours if argument is acceptable
    if(hours >= 0 && hours < 24)
        hour = hours;
}

void Clock::set_minute(int minutes)
{   
    //sets mins if argument is acceptable
    if(minutes >= 0 && minutes < 60)
        minute = minutes;
}

void Clock::set_second(int seconds)
{   
    //sets secs if argument is acceptable
    if(seconds >= 0 && seconds < 60)
        second = seconds;
}

void Clock::increment()
{   
    //converts hms to seconds with helper function
    int seconds = hms_to_sec();
    //increments seconds
    seconds++;
    //converts seconds back to hms with helper function
    sec_to_hms(seconds);
}

void Clock::decrement()
{
    //converts hms to seconds
    int seconds = hms_to_sec();
    //decrements seconds
    seconds--;
    //converts seconds back to hms with helper function
    sec_to_hms(seconds);
}

void Clock::add_seconds(int seconds_to_add)
{
    //converts hms to seconds
    int seconds = hms_to_sec();
    //adds argument(amount of seconds) to total secs
    seconds += seconds_to_add;
    //converts seconds back to hms
    sec_to_hms(seconds);
}

int Clock::hms_to_sec()
{
    return hour * 3600 + minute * 60 + second;
}

void Clock::sec_to_hms(int seconds)
{
    //if seconds is negative, add the neg seconds to total seconds in a 24h
    if(seconds < 0)
        seconds = 86400 + seconds;
    hour = seconds / 3600; //sets hour value
    //checks if hour is > 24 and adjusts accordingly
    if(hour >= 24)
        hour = hour % 24;
    minute = seconds % 3600 / 60; //sets the minute value
    //checks if minutes are >24 and adjusts accordingly
    if(minute >= 60)
        minute = minute % 60;
    //sets second value to the remainder after taking away all minutes
    second = seconds % 60;
}