#include <cmath>
const double PI = 3.141592653589793238463;
using namespace std;

class Point {
    double x;
    double y;
    double r;
    double a;
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
        r = sqrt(pow(x, 2) + pow(y, 2));
        if (x > 0 and y >= 0) {
            a = atan(y / x);
        }
        else if (x > 0 and y < 0) {
            a = atan(y / x) + 2 * PI;
        }
        else if (x < 0) {
            a = atan(y / x) + PI;
        }
        else if (x == 0 and y > 0) {
            a = PI / 2;
        }
        else if (x == 0 and y < 0) {
            a = 3 * PI / 2;
        }
        else {
            a = 0;
        }
    }

    double get_x() {
        return x;
    }

    double get_y() {
        return y;
    }

    double get_r() {
        return r;
    }

    double get_a() {
        return a;
    }

    void set_x(double x) {
        this->x = x;
        r = sqrt(pow(x, 2) + pow(y, 2));
        if (x > 0 and y >= 0) {
            a = atan(y / x);
        }
        else if (x > 0 and y < 0) {
            a = atan(y / x) + 2 * PI;
        }
        else if (x < 0) {
            a = atan(y / x) + PI;
        }
        else if (x == 0 and y > 0) {
            a = PI/2;
        }
        else if (x == 0 and y < 0) {
            a = 3*PI / 2;
        }
        else{
            a = 0;
        }
    }

    void set_y(double y) {
        this->y = y;
        r = sqrt(pow(x, 2) + pow(y, 2));
        if (x > 0 and y >= 0) {
            a = atan(y / x);
        }
        else if (x > 0 and y < 0) {
            a = atan(y / x) + 2 * PI;
        }
        else if (x < 0) {
            a = atan(y / x) + PI;
        }
        else if (x == 0 and y > 0) {
            a = PI / 2;
        }
        else if (x == 0 and y < 0) {
            a = 3 * PI / 2;
        }
        else {
            a = 0;
        }
    }

    void set_r(double r) {
        this->r = r;
        x = r * cos(a);
        y = r * sin(a);
    }

    void set_a(double a) {
        this->a = a;
        x = r * cos(a);
        y = r * sin(a);
    }
};
