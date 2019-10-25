#include <iostream>
#include "Date.h"
#include "Text.h"
#include "BlogEntry.h"
using namespace std;
/*Constructor
 Pre: none
 Post: Default constructor. Creates a date that represents the current date. */

Date::Date()
{
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    day = current->tm_mday;
    month = current->tm_mon + 1;
    year = current->tm_year + 1900;
}


/*Constructor
 Pre: parameter must represenr a valid date
 Post: Constructor. Creates a date that represents the specified date */

Date::Date(int day, int month, int year) throw (logic_error)
    :day(day), month(month), year(year)
{
    if(month < 1 || month > 12)
    {
        throw logic_error("Month not in valid range");
    }
    if(year < 1)
    {
        throw logic_error("Year is invalid.");
    }
    if(day < daysInMonth(month,year))
    {
        throw logic_error("Day is invalid");
    }
}



/*Constructor
 Pre: none
 Post: return the value of day */

int Date::getDay() const
{
    return day;
}


/*Constructor
 Pre: none
 Post: return the value of month */
int Date::getMonth() const
{
    return month;
}


/*Constructor
 Pre: none
 Post: return the value of year */
int Date::getYear() const
{
    return year;
}


/*Constructor
 Pre: year is greater than 1901 A.D.
 Post: if the specified year is a leap year, returns true. Else return false */
bool Date::isLeapYear(int year)
{
    bool result = true;
    while(year > 1901)
    {
        if((year % 4 == 0) || (year % 100 == 0 && year % 400 == 0))
           {
               return result;
           }
           else
           {
               result = false;
               return result;
           }
    }
    result = false;
    return result;
}


/*Constructor
 Pre: year is greater than 1901 A.D.
 Post: returns the number of days in the specified month. */
int Date::daysInMonth(int month, int year)
{
    while(year > 1901)
    {
        if(month == 2)
        {
            if(isLeapYear(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
        {
            return 31;
        }
        else
        {
            return 30;
        }
    }
    return 0;
}


/*Constructor
 Pre: none
 Post: outputs the date in the same format as the showDtructure function. */
ostream& operator<< (ostream& out, const Date& date)
{
    return out << date.month << "/" << date.day << "/" << date.year;
}

void Date::showStructure() const
{
    cout << month << "/" << day << "/" << year << endl;
}

int Date::getDayOfWeek() const
{
    return 0;
}

/* Programming Exercise 3
bool Date::operator== (const Date& other) const
{
   return (month == other.getMonth() && day == other.getDay() && year == other.getYear());
}

bool Date::operator< (const Date& other ) const
{
    bool result = false;
    if(year < other.getYear())
    {
        result = true;
    }
    else if(year == other.getYear() && month < other.getMonth())
    {
        result=true;
    }
    
    else if(year == other.getYear() && month == other.getMonth() && day < other.getDay())
    {
        result = true;
    }
    return result;
}

bool Date::operator > (const Date& other) const
{
    bool result = false;
    if(year > other.getYear())
    {
        result = true;
    }
    else if(year == other.getYear() && month > other.getMonth())
    {
        result=true;
    }
    
    else if(year == other.getYear() && month == other.getMonth() && day > other.getDay())
    {
        result = true;
    }
    return result;
}
*/




           
        
