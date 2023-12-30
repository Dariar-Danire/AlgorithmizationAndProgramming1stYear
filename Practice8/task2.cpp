struct Point; // Неполное определение структуры (класса). Недоступны параметры, методы структуры (класса)

struct Vector {
    int x = 0, y = 0;

    Vector(const Point& p1, const Point& p2);
};

struct Point { // Полное определение структуры. Доступно всё.
    int x = 0, y = 0;

    Point(int p_x, int p_y) {
        this->x = p_x;
        this->y = p_y;
    }

    void move(Vector v) {
        this->x += v.x;
        this->y += v.y;
    }
};

Vector::Vector(const Point& p1, const Point& p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
}
