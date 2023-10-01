#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double a, b;
    cin >> a;
    cout << "\n";
    cin >> b;

    double sum = pow(a, 2) + pow(b, 2);
    double c = pow(sum, 0.5);
    cout << c;
}
