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
    cout << "~data" << endl;
}

data::data(const data &d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

void data::Print()
{
    cout << _year << "-" << _month << "-" << _day << endl;
}

bool data::operator<(const data &d1)
{
    if (_year < d1._year)
    {
        return true;
    }
    else if (_year == d1._year && _month < d1._month)
    {
        return true;
    }
    else if (_year == d1._year && _month == d1._month && _day < d1._day)
    {
        return true;
    }
    return false;
}

bool data::operator>(const data &d1)
{
    if (_year > d1._year)
    {
        return true;
    }
    else if (_year == d1._year && _month > d1._month)
    {
        return true;
    }
    else if (_year == d1._year && _month == d1._month && _day > d1._day)
    {
        return true;
    }
    return false;
}

bool data::operator==(const data &d1)
{
    return _year == d1._year && _month == d1._month && _day == d1._day;
}
bool data::operator!=(const data &d1)
{
    return !(_year == d1._year && _month == d1._month && _day == d1._day);
}

bool data::operator>=(const data &d1)
{
    return *this > d1 || *this == d1;
}

bool data::operator<=(const data &d1)
{
    return *this < d1 || *this == d1;
}

int data::getday(int year, int month)
{
    const int dayarr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        return 29;
    }
    return dayarr[month];
}

data &data::operator+=(int day) // 不会产生拷贝，节省空间
{
    _day += day;
    while (_day > getday(_year, _month))
    {
        _day -= getday(_year, _month);
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
    tem += day; // 这里直接调用上面的+=
    return tem;
}

data data::operator++()
{
    *this += 1;
    return *this;
}

data data::operator++(int)
{
    data tem(*this);
    *this += 1;
    return tem;
}

data &data::operator-=(int day)
{
    if (day < 0) // 如果输入day 是一个负数
    {
        return *this += -day;
    }
    _day -= day;
    while (_day <= 0)
    {
        --_month;
        if (_month == 0)
        {
            --_year;
            _month = 12;
        }
        _day += getday(_year, _month);
    }
    return *this;
}

data data::operator-(int day)
{
    data tem(*this);
    *this -= day;
    return tem;
}

int data::operator-(const data &d1)
{
    data max = *this;
    data min = d1;
    int flag = 1;
    if (max < min)
    {
        max = d1;
        min = *this;
        flag = -1;
    }
    int count = 0;
    while (min < max)
    {
        min += 1;
        count++;
    }
    return flag * count;
}

ostream &operator<<(ostream &out, const data &d)
{
    out << d._year << "-" << d._month << "-" << d._day << endl;

    return out;
}

istream &operator>>(istream &in, data &d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
