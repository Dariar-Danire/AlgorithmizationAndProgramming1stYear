#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> GetVectorOfMaximumValues(map<string, int> words) {
    int maxCnt = 0;
    vector<string> resultWords;

    for (auto& wordCnt : words) {
        if (wordCnt.second > maxCnt) {
            maxCnt = wordCnt.second;

            resultWords.clear();
            resultWords.push_back(wordCnt.first);
        }
        else if (wordCnt.second == maxCnt) {
            resultWords.push_back(wordCnt.first);
        }
    }

    return resultWords;
}

int main() {
    int cntWords;
    cin >> cntWords;

    map<string, int> words;
    for (int i = 0; i < cntWords; i++) {
        string word;
        cin >> word;
        words[word]++; // Если элемент с ключом word нет в словаре, он определит его как 0, иначе — прибавит единицу.
    }

    vector<string> resultWords = GetVectorOfMaximumValues(words);
    sort(resultWords.begin(), resultWords.end());

    for (auto& word : resultWords) cout << word << " ";
}
