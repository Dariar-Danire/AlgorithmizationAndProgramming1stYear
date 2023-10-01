#include <iostream>
#include <string>
using namespace std;

string encode(string str) {
    string encoding = "";
    int count;

    for (int i = 0; str[i]; i++) {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++, i++;
        }

        if (count > 1){
            encoding += str[i] + to_string(count);
        }
        else {
            encoding += str[i];
        }
    }

    return encoding;
}

int main() {
    string str;
    cin >> str;

    cout << encode(str);

    
}
