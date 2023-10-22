#include <iostream>
#include <set>

using namespace std;

int main() {
    int cntOfWords;
    cin >> cntOfWords;

    set<string> words;

    for (int i = 0; i < cntOfWords; i++) {
        string wrd;
        cin >> wrd;

        words.insert(wrd);
    }

    int cntWords;
    cin >> cntWords;

    set<string> resultWords;
    for (int i = 0; i < cntWords; i++) {
        string word;
        cin >> word;

        if (words.find(word) != words.end()) {
            resultWords.insert(word);
        }
    }

    if (resultWords.size() == 0) {
        cout << -1;
        return 0;
    }

    for (auto& word : resultWords) {
        cout << word << ' ';
    }
}
