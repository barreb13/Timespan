// Brent Barrese
// TODO Created by XXX on YYY.
//

#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class TimeSpan 
{
    friend ostream &operator<<(ostream& output, const TimeSpan& timespan);

public:

    //constructor with initializer list
    TimeSpan(double hours = 0, double minutes = 0, double seconds = 0);
    
    // add
    TimeSpan operator+(const TimeSpan& timespan) const;
  
    // subtract
    TimeSpan operator-(const TimeSpan& timespan) const;
 
     // check equality
    bool operator==(const TimeSpan& timespan) const;
  
    // check if not equal
    bool operator!=(const TimeSpan& timespan) const;
  
    // multiply timespan by a number
    TimeSpan operator*(int number);
    
    // Check if greater than >
    bool operator>(const TimeSpan& timespan)const;

    // Check if less than <
    bool operator<(const TimeSpan& timespan)const;

    //Check if greater than or equal to >=
    bool operator>=(const TimeSpan& timespan)const;

    //Check if less than or equal to <=
    bool operator<=(const TimeSpan& timespan)const;

    // operator +=
    TimeSpan operator+=(const TimeSpan& timespan) const;

    // operator -=
    TimeSpan operator-=(const TimeSpan& timespan) const;

    //Convert time 
    string convertTime() const;

    //Accessor to get timeInSeconds
    int getTimeInSeconds() const;

private:
    double hour;
    double minute;
    double second;
    int timeInSeconds;

    //maybe needed?
    string convertedTime;

    //Set the total time in Seconds
    void setTimeInSeconds();
};
