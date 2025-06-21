#include "test.h"
void test()
{
      data d1(2023, 6, 23);
    d1.Print();
    d1 += 100;
    d1.Print();
    data d2(d1);
}

int main()

{
    test();
    return 0;
}
