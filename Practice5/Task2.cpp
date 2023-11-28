class Water {
public:
    int temperature = 0;
    Water(int temperaturei) {
        temperature = temperaturei;
    }
    Water() {}
};

class Teapot {
public:
    Water water;
    Teapot(Water wateri) { 
        water.temperature = wateri.temperature;
    }

    bool is_boiling() {
        if (water.temperature >= 100) {
            return true;
        }
        return false;
    }

    void heat_up(int temp_up) {
        water.temperature += temp_up;
    }
};
