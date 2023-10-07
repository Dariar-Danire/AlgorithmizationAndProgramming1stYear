#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

Student make_student(std::string line) {
    int pos = line.find(';');

    std::string res_name = line.substr(0, pos);
    std::string res_group = line.substr(pos + 1);

    Student man {res_name, res_group};
    return man;
}

bool is_upper(Student man1, Student man2) {
    if (man1.group == man2.group) {
        return man1.name < man2.name;
    }

    return man1.group < man2.group;
}

void print(std::vector<Student> students) { //Имеется в виду отсортированный вектор
    if (students.size() == 0) {
        std::cout << "Empty list!";
    }
    else {
        std::cout << students[0].group << std::endl;
    	std::cout << "- " << students[0].name << std::endl;
        for (int i = 1; i < students.size(); i++) {
            if (students[i].group != students[i - 1].group) {
                std::cout << students[i].group << std::endl;
            }
            std::cout << "- " << students[i].name << std::endl;
        }
    }
}

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}
