#include "test.h"
void test()
{
    data d1(2023, 6, 23);
    data d2(2023, 6, 30);
    cin >> d1 >> d2;
    cout << d1 << d2;
        d1 += 100;
        cout << d1;
        d1 -= 100;
        cout << d1;

        cout << d2;

        cout << (d1 - d2) << endl;
}

int main()

{
    test();
    return 0;
}
