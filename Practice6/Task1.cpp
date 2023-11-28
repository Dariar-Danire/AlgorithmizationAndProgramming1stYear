# define M_PI           3.14159265358979323846

class Shape {
public:
    // Это чисто виртуальная функция, которая реализуется в классах-потомках
    virtual double getPerimeter() = 0;
};

class Rectangle : public Shape {
    int a, b;
    public:

        Rectangle(int c, int d) {
            this->a = c;
            this->b = d;
        }

        double getPerimeter() {
            return 2 * (a + b);
        }
};

class Circle : public Shape {
    int r;
    public:

        Circle(int R) {
            this->r = R;
        }

        double getPerimeter() {
            return 2 * M_PI * r;
        }
};

class Triangle : public Shape {
    int a, b, c;
    public:

        Triangle(int d, int n, int m) {
            this->a = d;
            this->b = n;
            this->c = m;
        }

        double getPerimeter() {
            if (a + b > c && a + c > b && b + c > a) {
                return a + b + c;
            }
            return 0;
        }
};
