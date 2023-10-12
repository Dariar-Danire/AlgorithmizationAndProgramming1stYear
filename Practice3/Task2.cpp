#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool  SequenceIsValid(std::string sourceString) { 
    stack<char> brackets;

    for (auto& symbol : sourceString) {
        switch (symbol) {
        case '(': 
            brackets.push(')'); 
            break;
        case '[':
            brackets.push(']');
            break;
        case '{':
            brackets.push('}');
            break;

        case ')':
        case ']':
        case '}':
            if (brackets.empty() || brackets.top() != symbol) {
                return false;
            }
            brackets.pop();
            break;
        default:
            break;
        }
    }
    
    return brackets.empty();
}


int main() {
    string sourceString;
    getline(cin, sourceString, '!');

    cout << (SequenceIsValid(sourceString) ? "YES":"NO");

}
