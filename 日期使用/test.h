#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;

class data
{

public:
    data(int year = 1900, int month = 1, int day = 1); // 构造函数
    ~data();                                           // 析构函数
    data(const data &d);                               // 拷贝构造
    void Print();                                      // 打印
    // 比较
    bool operator<(const data &d1);
    bool operator>(const data &d1);
    bool operator==(const data &d1);
    bool operator!=(const data &d1);
    bool operator>=(const data &d1);
    bool operator<=(const data &d1);
    // 天数获取
    int getday(int year, int month);
    // 加减
    data &operator+=(int day);
    data operator+(int day); // operator+通过operator+=来实现
    data operator++();       // 前置++  ++x
    data operator++(int);    // 后置++  x++
    data &operator-=(int day);
    data operator-(int day);
    // 日期相减d1-d2
    int operator-(const data &d1);
    // 自定义类型流插入
    friend ostream &operator<<(ostream &out, const data &d);
    // 自定义类型流输出
    friend istream &operator>>(istream &in, data &d);

    // private:
    int _year;
    int _month;
    int _day;
};
