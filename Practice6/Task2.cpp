class Employee {
public: 
    std::string name, post;
    int salary_for_month;

    virtual double bonus(double percent) {
        return salary_for_month * percent;
    }

    double salary() {
        return this->salary_for_month  + bonus(bonuses[post]);
    }

    friend std::ostream& operator<<(std::ostream& out, Employee& employee);

    Employee(std::string name_e, std::string post_e, int money) {
        this->name = name_e;
        this->post = post_e;
        this->salary_for_month = money;
    }
};

class Manager : public Employee {
public:
    Manager(std::string name_m, int money_m = 16242) : Employee(name_m, "manager", money_m) {
    }

    double bonus(double percent) override {
        if (percent < 0.1) {
            percent = 0.1;
        }

        double manager_bonus = bonuses[post] < 0.1 ? 0.1 : bonuses[post];

        return this->salary_for_month * percent;
    }
};

std::ostream& operator<<(std::ostream& out, Employee& employee) {
    out << employee.name << " (" << employee.post << "): " << employee.salary_for_month + employee.bonus(bonuses[employee.post]);
    return out;
}
