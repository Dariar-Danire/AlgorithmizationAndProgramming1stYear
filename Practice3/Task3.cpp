#include <iostream>
#include <stack>

/*
Рассмотреть следующие случаи:
1) Чтение дву- и более значных чисел
2) Run-time error в компиляторе GCC C++ 17
*/

using namespace std;

struct BinaryOperation {
    char type;
    bool left_associative;
    bool right_associative;
    int priority;
};

const int len = 6;

bool FindInTheArrayOfOperators(BinaryOperation Operations[], char operation) {
    for (int i = 0; i < len; i++) {
        if (Operations[i].type == operation) {
            return true;
        }
    }

    return false;
}

int ReturnPriority(BinaryOperation Operations[], char operation) {
    int priority;

    for (int i = 0; i < len; i++) {
        if (Operations[i].type == operation) {
            return Operations[i].priority;
        }
    } // Не факт, что это правильно. Возможно, придётся удалять openBracket из массива операторов (2)

    return 7; // Скобка и начальный незначащий элемент стека(4)
}

bool isLeftAssociative(char operation, BinaryOperation Operations[]) {
    for (int i = 0; i < len; i++) {
        if (Operations[i].type == operation) {
            return Operations[i].left_associative;
        } // Если в operation залезет скобка, всё полетит к чертям собачьим! (1)
    }

    return false; // Обновлено. (2) // Уже не нужно, но оставлю (3) // Скобка (4)
}

string TranslationIntoReversePolishNotation(string sourceString) {
    string resultString = "";
    stack<char> stack;
    stack.push('#');

    BinaryOperation remain{ '%', true, false, 5 };
    BinaryOperation degree{ '^', false, true, 4 };
    BinaryOperation comp{ '*', true, false, 5 };
    BinaryOperation division{ '/', true, false , 5 };
    BinaryOperation sum{ '+', true, false, 6 };
    BinaryOperation diff{ '-', true, false, 6 };
    BinaryOperation binaryOperations[len]{ remain, degree, division, comp, sum, diff };

    for (int i = 0; i < sourceString.size(); i++) {                    
                                                                   // 3+4*2/(1-5)^2
        if (sourceString[i] >= '0' && sourceString[i] <= '9') {   // Стек: +*
            resultString += sourceString[i];                     // Выход: 3 4 2 

            if (sourceString[i + 1] < '0' || sourceString[i + 1] > '9') {
                resultString += ' ';
            }
        }

        else if (sourceString[i] == '(') {
            stack.push('('); // Было: stack.push('(');
        }

        else if (sourceString[i] == ')') {
            while (stack.size() != 1 && stack.top() != '(') {
                resultString += stack.top();
                resultString += ' ';
                stack.pop();
            }

            if (stack.size() != 1) {
                stack.pop();
            }
            else {
                return "Error!";
            }
        }

        else if (FindInTheArrayOfOperators(binaryOperations, sourceString[i])) { // // Может получиться так, что в ходе этого while появится какая-нибудь скобка, так что стоит рассмотреть вариант с return -1

            // МОЖЕТ ПОТРЕБОВАТЬСЯ ВЕРНУТЬ <=
            while (ReturnPriority(binaryOperations, stack.top()) < ReturnPriority(binaryOperations, sourceString[i]) || (ReturnPriority(binaryOperations, stack.top()) == ReturnPriority(binaryOperations, sourceString[i]) && isLeftAssociative(stack.top(), binaryOperations))) {
                resultString += stack.top(); // Просто игнорируем скобку, если такая появляется. МОЖЕТ ПОНАДОБИТЬСЯ ПЕРЕПРЫГИВАТЬ ЧЕРЕЗ СКОБКУ И ИДТИ ДАЛЬШЕ ПО ЦИКЛУ
                resultString += ' ';
                stack.pop();
            }

            stack.push(sourceString[i]); // Возможно, понадобится высчитывать понимать была ли открывающая скобка раньше или нет, чтобы повысить приоритет операторов
        }
    }

    while (stack.size() > 1) {
        if (stack.top() == '(') {
            return "Error!";
        }

        resultString += stack.top();
        resultString += ' ';
        stack.pop();
    }

    resultString.erase(resultString.size() - 1, resultString.size()); //Удаляем лишний пробел

    return resultString;

}

int main() {

    string sourceString;
    cin >> sourceString;

    string resultString = TranslationIntoReversePolishNotation(sourceString);

    cout << resultString;
}
