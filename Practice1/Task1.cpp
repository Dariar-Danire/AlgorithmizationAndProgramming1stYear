#include <iostream>
#include <math.h> // ОБЯЗАТЕЛЬНО ДЛЯ КОМПИЛЯТОРА GCC c++ 17 7.3

using std::cout;

int main()
{
    double a = 1 / pow(3,2);
    double b = 1 / (5 * pow(3,2));
    double c = 1 / (7 * pow(3,3));
    double d = 1 / (9 * pow(3, 4));
    double m = 1 / (11 * pow(3, 5));

    double res = sqrt(12) * (1 - a + b - c + d - m);
    cout << res;
}
