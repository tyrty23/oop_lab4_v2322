#include "Date.h"

ostream& operator<<(ostream& out, Date d)
{
    out << setw(2) << d.day
        << setw(10) << d.month
        << setw(4) << d.year;
    return out;
}

istream& operator>>(istream& in, Date d)
{
    in >> d.day >> d.month >> d.year;
    return in;
}


Date::Date()
{
    day = 1;
    month = "январь";
    year = 1970;
}

Date::Date(int d, string m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::GetDay()
{
    return day;
}

void Date::SetDay(int val)
{
    day = val;
}

string Date::GetMonth()
{
    return month;
}

void Date::SetMonth(string val)
{
    month = val;
}

int Date::GetYear()
{
    return year;
}

void Date::SetYear(int val)
{
    year = val;
}
