#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int n, m;

    cin >> n;
    vector<int> sequence1(n);
    for (auto& num: sequence1) cin >> num;

    cin >> m;
    vector<int> sequence2(m);
    for (auto& num : sequence2) cin >> num;

    vector<int> res;
    for (auto& num : sequence2) res.push_back(num);
    for (auto& num : sequence1) res.push_back(num);

    sort(res.begin(), res.end());

    for (auto& num : res) cout << num << " ";  
    
}
