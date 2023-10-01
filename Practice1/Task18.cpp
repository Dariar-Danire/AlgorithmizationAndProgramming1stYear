#include <iostream>
#include <string>
using namespace std;

const char alphabet[27]{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

string DefiningTheColumnName(int sourceNumber) {

    string resultCodeOfTitle = "";

    if (sourceNumber > 26) {
        while (sourceNumber > 0) {
            int remainder = sourceNumber % 26;
            int letterEquivalentOfTheRemainder = alphabet[remainder - 1];
            resultCodeOfTitle += letterEquivalentOfTheRemainder;
            sourceNumber = sourceNumber / 26;
        }
        string resCodeOfTitle;
        for (int i = resultCodeOfTitle.length() - 1; i >= 0; i--) {
            resCodeOfTitle += resultCodeOfTitle[i];
        }
        return resCodeOfTitle;
    }
    
    resultCodeOfTitle += alphabet[sourceNumber - 1]; 
    return resultCodeOfTitle;
}

int main() {
    /*string str;
    cin >> str;

    cout << encode(str);*/

    int number;
    cin >> number;

    cout << DefiningTheColumnName(number);

}
