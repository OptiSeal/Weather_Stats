// TIME.cpp - Time IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

#include "TIME.h"

//---------------------------------------------------------------------------------

        //Default Constructor
    Time::Time()
    :hours(0), mins(0), secs(0)
    {

    }

        //Sets initial time. If the time is not valid, a message will be thrown.
    Time::Time(int initial_Hours, int initial_Mins, int initial_Secs)
    :hours(0), mins(0), secs(0)
    {
        if(initial_Hours <=23 && initial_Mins <=59 && initial_Secs <=59)
        {
            hours = initial_Hours;
            mins = initial_Mins;
            secs = initial_Secs;
        }
        else
            throw "Time is invalid";
    }

        //Sets the time. If time is not valid, a message will be thrown to caller.
    void Time::set_Time(int new_Hours, int new_Mins, int new_Secs)
    {
        if(new_Hours <=23 && new_Mins <=59 && new_Secs <=59)
        {
            hours = new_Hours;
            mins = new_Mins;
            secs = new_Secs;
        }
        else
            throw "Time is invalid";
    }

        //Sets hours
    void Time::set_Hours(int new_Hours)
    {
        if(new_Hours <=23)
            hours = new_Hours;
        else
            throw "Hours are not valid ";
    }

        //Returns hours
    int Time::get_Hours() const
    {
        return hours;
    }

        //Sets minutes
    void Time::set_Mins(int new_Mins)
    {
        if(new_Mins <=59)
            mins = new_Mins;
        else
            throw "Minutes are not valid ";
    }

        //Returns minutes
    int Time::get_Mins() const
    {
        return mins;
    }

        //Sets seconds
    void Time::set_Secs(int new_Secs)
    {
        if(new_Secs <=59)
            secs = new_Secs;
        else
            throw "Seconds are not valid ";
    }

        //Returns seconds
    int Time::get_Secs() const
    {
        return secs;
    }

        //Checks if time is the same
    bool Time::operator ==(const Time &otherT) const
    {
        return ((this->hours == otherT.hours) &&
                (this->mins == otherT.mins) &&
                (this->secs == otherT.secs));
    }

     bool Time::operator<(const Time &otherT) const
     {
         return ((this->hours < otherT.hours) ||
                ((this->hours == otherT.hours) && (this->mins < otherT.mins)) ||
                ((this->hours == otherT.hours) && (this->mins == otherT.mins) && (this->secs < otherT.secs)));
     }

// ------------------------------------------------------------------------------------------------------
// END of Time IMPLENTATION FILE
