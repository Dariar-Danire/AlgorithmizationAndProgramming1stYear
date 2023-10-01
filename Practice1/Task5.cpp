#include <iostream>

using std::cout;
using std::cin;

int main()
{
    double m, h; // m - масса тела в кг, h - рост в м
    cin >> m >> h;
    double I = m / (h*h);
    cout << I;
}
