#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    
    int cntUsers;
    cin >> cntUsers;

    map<string, int> users;
    for (int i = 0; i < cntUsers; i++) {
        string GUser;
        cin >> GUser;

        int pos = GUser.find(';');
        users[GUser.substr(0, pos)] = stoi(GUser.substr(pos + 1));
    }

    int cntFindUsers;
    cin >> cntFindUsers;

    for (int i = 0; i < cntFindUsers; i++) {
        string findUser;
        cin >> findUser;

        map<string, int>::iterator iter = users.find(findUser);
        if (iter == users.end()) {
            cout << endl << "Error!";
            break;
        }
         
        cout << (*iter).second << ' ';
    }
    
}
