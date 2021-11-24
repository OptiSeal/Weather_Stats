// DATE.CPP - Date IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

#include "DATE.h"

//---------------------------------------------------------------------------------

        //Default Constructor
    Date::Date()
        :day{1},month{1},year{1920}
    {

    }


        //Constructor
    Date::Date(unsigned initial_Day, unsigned initial_Month, unsigned initial_Year)
        :day{1},month{1},year{1920}
    {
        if(isValid_Date(initial_Day,initial_Month, initial_Year) == true)
        {
            day = initial_Day;
            month = initial_Month;
            year = initial_Year;
        }
        else
            throw "Date is invalid";
    }


        //Copies other date to this date
    void Date::copy_Date(const Date& new_Date)
    {
        day = new_Date.get_Day();
        month = new_Date.get_Month();
        year = new_Date.get_Year();
    }


        //Reset date to default values
    void Date::reset_Date()
    {
        day = 1;
        month = 1;
        year = 1920;
    }


        //Checks if date is valid
    bool Date::isValid_Date(unsigned d, unsigned m, unsigned y)
    {
        if(d >= 1 && m <= 12)
        {
            // If day falls within these months and day is no greater than 31.
            if(m == 1 || m == 3 || m == 5 ||
                    m == 7 || m == 8 || m == 10
                    || m == 12)
            {
                if(d <= 31)
                {
                    return true;
                }
            }
            else  // If day falls within these months and day is no greater than 30.
            {
                if(m == 4 || m == 6 || m == 9 || m == 11)
                {
                    if(d <= 30)
                    {
                        return true;
                    }

                // If day falls within the month of February, the year is checked
                // if it is a leap year and if so the day is no greater than 29.
                }
                else
                {
                    if(m == 2 && d < 29)
                    {
                        return true;
                    }
                    else
                    {
                        if(d == 29)
                        {
                            return is_LeapYear(y);
                        }
                    }
                }
            }
        }

        return false;
    }


        //Checks if the year provided is a leap year
    bool Date::is_LeapYear(unsigned y)
    {
        // Checks if year can be evenly divided by 4.
        if(y % 4 == 0)
        {
            //Checks if year can be evenly divided by 100. If not, return true.
            if(y % 100 == 0)
            {
                //Checks if year can be evenly divided by 400. If so, return true.
                if(y % 400 == 0)
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }

        return false;
    }


        //Sets the day
    void Date::set_Day(unsigned new_Day)
    {
        if(isValid_Date(new_Day, month, year) == true)
            day = new_Day;
        else
            throw "Date is not valid ";
    }


        //Retrieves the day
    unsigned Date::get_Day() const
    {
        return day;
    }


        //Sets the month
    void Date::set_Month(unsigned new_Month)
    {
        if(isValid_Date(day, new_Month, year) == true)
            month = new_Month;
        else
            throw "Date is not valid ";
    }


        //Retrieves the month
    unsigned Date::get_Month() const
    {
        return month;
    }


        //Sets the year
    void Date::set_Year(unsigned new_Year)
    {
        if(isValid_Date(day, month, new_Year) == true)
            year = new_Year;
        else
            throw "Date is not valid ";
    }


        //Retrieves the year
    unsigned Date::get_Year() const
    {
        return year;
    }

        //Checks if dates are equal
    bool Date::operator==(const Date &o_Date) const
    {
        return ((this->day == o_Date.day) &&
                (this->month == o_Date.month) &&
                (this->year == o_Date.year));
    }

        //Compares dates and checks if this date is less than the other date object
    bool Date::operator<(const Date &o_Date) const
    {
        return  ((this->year < o_Date.year) ||
                ((this->year == o_Date.year) && (this->month < o_Date.month)) ||
                ((this->year == o_Date.year) && (this->month == o_Date.month) && (this->day < o_Date.day)));
    }


// ------------------------------------------------------------------------------------------------------
// END of Date IMPLEMENTATION FILE
