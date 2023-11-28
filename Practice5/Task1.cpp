class Cat {
public:
    bool alive = rand() % 2;
    bool is_alive() {
        return alive;
    }
};

class Box {
public:
    Cat open() {
        Cat cat;
        return cat;
    }
};
