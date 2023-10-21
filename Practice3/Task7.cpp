#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool funcSort(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second > p2.second) {
        return true;
    }
    else if (p1.second == p2.second && p1.first < p2.first) {
        return true;
    }
    else {
        return false;
    }
}

vector<pair<string, int>> GetVectorOfValues(map<string, int> words) {

    vector<pair<string, int>> resultWords;
    for (auto& word : words) {
        resultWords.push_back(word);
    }
    sort(resultWords.begin(), resultWords.end(), funcSort);


    return resultWords;
}

int main() {
    string target;
    cin >> target;

    ifstream file("data.txt");
    
    string key1, key2;
    file >> key1 >> key2;
    
    map<string, int> words; // Будет пуст, если слова target в файле нет
    while (!file.eof()) {   
        if (key1 == target) {
            words[key2]++;
        }

        key1 = key2;
        file >> key2;
    }

    if (words.empty()) {
        cout << "-";
    }
    else {
        vector<pair<string, int>> resultWords = GetVectorOfValues(words);

        int maxCnt = 3;
        for (auto& word : resultWords) {
            if (maxCnt > 0) {
                cout << word.first;
                if (maxCnt != 1) {
                    cout << ' ';
                }
                maxCnt--;
            }
            else {
                break;
            }
        }
    }
}
