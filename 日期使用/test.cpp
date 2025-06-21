#include "test.h"
data::data(int year, int month, int day)
{
    cout << "data()" << endl;
    _year = year;
    _month = month;
    _day = day;
}

data::~data()
{
    cout << "~data()" << endl;
}

void data::Print()
{
    cout << _year << "-" << _month << "-" << _day << endl;
}

bool data::operator<(const data &d2)
{
    if (_year < d2._year)
    {
        return true;
    }
    else if ((_year == d2._year) && (_month < d2._month))
    {
        return true;
    }
    else if ((_year == d2._year) && (_month == d2._month) && (_day < d2._day))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool data::operator==(const data &d2)
{
    return (_year == d2._year) && (_month == d2._month) && (_day == d2._day);
}

bool data::operator<=(const data &d2)
{
    return *this < d2 || *this == d2;
}

bool data::operator>(const data &d2)
{
    if (_year > d2._year)
    {
        return true;
    }
    else if ((_year == d2._year) && (_month > d2._month))
    {
        return true;
    }
    else if ((_year == d2._year) && (_month == d2._month) && (_day > d2._day))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool data::operator>=(const data &d2)
{
    return *this > d2 || *this == d2;
}

bool data::operator!=(const data &d2)
{
    return !(*this == d2);
}

int data::getday(int month, int year)
{
    static int dayarr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    return dayarr[month];
}

data &data::operator+=(int day)
{
    _day += day;
    while (_day > getday(_month, _year))
    {
        _day -= getday(_month, _year);
        _month++;
        if (_month == 13)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

data data::operator+(int day)
{
    data tem(*this);
    tem += day;
    return tem;
}
