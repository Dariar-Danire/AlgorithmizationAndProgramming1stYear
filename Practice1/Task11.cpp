#include <iostream>
#include <math.h> // ОБЯЗАТЕЛЬНО ДЛЯ КОМПИЛЯТОРА GCC c++ 17 7.3

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int difAB = abs(a - b);
    int difAC = abs(a - c);

    if (difAB > difAC) 
    {
        cout << "C " << difAC;
    }
    else 
    {
        cout << "B " << difAB;
    }
}
