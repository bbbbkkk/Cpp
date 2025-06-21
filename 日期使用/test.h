#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;

class data
{
public:
    data(int year = 1900, int month = 1, int day = 1); // 构造函数
    ~data();                                           // 析构函数
    data(const data &d3)                               // 拷贝析构
    {
        cout << "data(const data&d3)" << endl;
        _year = d3._year;
        _month = d3._month;
        _day = d3._day;
    }
    void Print();
    bool operator<(const data &d2);
    bool operator==(const data &d2);
    bool operator<=(const data &d2);
    bool operator>(const data &d2);
    bool operator>=(const data &d2);
    bool operator!=(const data &d2);
    int getday(int month, int year);
    data &operator+=(int day);
    data operator+(int day);

    // private:
    int _year;
    int _month;
    int _day;
};