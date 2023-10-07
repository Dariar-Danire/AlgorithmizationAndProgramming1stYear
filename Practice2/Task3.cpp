#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int countOfOne(std::string a) {
    int cnt1 = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1') {
            cnt1++;
        }
    }
    return cnt1;
}

bool compare(std::string a, std::string b) {\
    int cnt1_a = countOfOne(a);
    int cnt1_b = countOfOne(b);

    if (cnt1_a == cnt1_b) { 
        return std::stoi(a) < std::stoi(b);
    }
    return cnt1_a > cnt1_b;
}

int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}
