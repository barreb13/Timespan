// Brent Barrese
// TODO Created by XXX on YYY.
//

#include "timespan.h"
#include <cstdlib>

// Constructor with 3 inputs AND Initializer list
TimeSpan::TimeSpan(double hours, double minutes, double seconds) 
    : hour{hours}, minute{minutes}, second{seconds}
{
    setTimeInSeconds();
}

//Operator to outstream to ss stream and print
ostream& operator<<(ostream& output, const TimeSpan& timespan) 
{
    //output << timespan.hour << ":" << timespan.minute << ":" << timespan.second;
    output << timespan.convertTime();
    return output;
}

//Overloaded + operator for addition
TimeSpan TimeSpan::operator+(const TimeSpan& timespan) const 
{
    TimeSpan ts(this->hour + timespan.hour, this->minute + timespan.minute, this->second + timespan.second);  
    return ts;
}

//Overloaded - operator for subtraction
TimeSpan TimeSpan::operator-(const TimeSpan& timespan) const 
{
    TimeSpan ts(this->hour - timespan.hour, this->minute - timespan.minute, this->second - timespan.second);
    return ts;
}

// Overloaded operator +=
TimeSpan TimeSpan::operator+=(const TimeSpan& timespan) const
{
    TimeSpan ts(this->hour + timespan.hour, this->minute + timespan.minute, this->second + timespan.second);
    return ts;
}

// Overloaded operator -=
TimeSpan TimeSpan::operator-=(const TimeSpan& timespan) const
{
    TimeSpan ts(this->hour - timespan.hour, this->minute - timespan.minute, this->second - timespan.second);
    return ts;
}

//Overloaded * operator for multiplication
TimeSpan TimeSpan::operator*(int number) 
{
    TimeSpan ts(this->hour * number, this->minute * number, this->second * number);
    return ts;
}

//Overloaded == operator to check for equality
bool TimeSpan::operator==(const TimeSpan& timespan) const 
{
    bool result = true;
    if (this->getTimeInSeconds() != timespan.getTimeInSeconds())
    {
        result = false;
    }
    return result;
}

//Overloaded != operator for testing inequality
bool TimeSpan::operator!=(const TimeSpan& timespan) const 
{
    bool result = true;
    if (this->getTimeInSeconds() == timespan.getTimeInSeconds())
    {
        result = false;
    }
    return result;
}

//Comparison operators
// Check if greater than >
bool TimeSpan::operator>(const TimeSpan& timespan)const
{
    bool result = true;
    if (this->getTimeInSeconds() < timespan.getTimeInSeconds())
    {
        result = false;
    }
    return result;
}

// Check if less than <
bool TimeSpan::operator<(const TimeSpan& timespan)const
{
    bool result = true;
    if (this->getTimeInSeconds() > timespan.getTimeInSeconds())
    {
        result = false;
    }
    return result;
}

//Check if greater than or equal to >=
bool TimeSpan::operator>=(const TimeSpan& timespan)const
{
    bool result = true;
    if (this->getTimeInSeconds() <= timespan.getTimeInSeconds())
    {
        result = false;
    }
    return result;
}

//Check if less than or equal to <=
bool TimeSpan::operator<=(const TimeSpan& timespan)const
{
    bool result = true;
    if (this->getTimeInSeconds() >= timespan.getTimeInSeconds())
    {
        result = false;
    }
    return result;
}

//Mutator
//Set the total time in Seconds
void TimeSpan::setTimeInSeconds()
{
    int hoursInSeconds = hour * 3600;
    int minutesInSeconds = minute * 60;
    int seconds = second;

    //Add everything to get TOTAL in seconds
    timeInSeconds = hoursInSeconds + minutesInSeconds + seconds;
}

//Accessor to get timeInSeconds
int TimeSpan::getTimeInSeconds() const
{
    return timeInSeconds;
}

//Function to turn variable totalSeconds into hh:mm:ss format
string TimeSpan::convertTime() const
{
    //string convertedTime;
    int totalSeconds = getTimeInSeconds();
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    stringstream temp;

    //if Seconds positive
    if (totalSeconds > 0)
    {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds - (hours * 3600)) / 60;
        seconds = totalSeconds - (hours * 3600) - (minutes * 60);

        temp << hours << ":"; 
        if (minutes < 10)
        {
            temp << "0" << minutes << ":";
        }
        else
        {
            temp << minutes << ":";
        }
        if (seconds < 10)
        {
            temp << "0" << seconds;
        }
        else
        {
            temp << seconds;
        }
    }
    // Handle negative case of time
    else
    {
        hours = abs(totalSeconds / 3600);
        minutes = abs((totalSeconds - (hours * 3600)) / 60);
        seconds = abs(totalSeconds - (hours * 3600) - (minutes * 60));

        temp << "-" << hours << ":"; 
        if (minutes < 10)
        {
            temp << "0" << minutes << ":";
        }
        else
        {
            temp << minutes << ":";
        }
        if (seconds < 10)
        {
            temp << "0" << seconds;
        }
        else
        {
            temp << seconds;
        }
    }
    //Return stringstream
    return temp.str();
}
