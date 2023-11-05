#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main() {
    ifstream jfile("data.json");
    
    if (!jfile.is_open()) {
        cout << "Error!";
        return 0;
    }

    json j_data;
    jfile >> j_data; // Необработанное исключение

    int UserID;
    cin >> UserID;

    int cnt = 0;
    for (const auto& project : j_data) {
        for (const auto& task : project["tasks"]) {
            if (task["user_id"] == UserID && task["completed"]) {
                cnt++;
            }
        }
    }

    cout << cnt;
}
