#include <iostream>
#include <math.h>

bool is_prime(int sourceNumber) {

    for (int d = 2; d <= std::floor(sqrt(sourceNumber)); d++) {
        if (sourceNumber % d == 0) {
            return false;
        }
    }

    return true;
}


int main() {
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
