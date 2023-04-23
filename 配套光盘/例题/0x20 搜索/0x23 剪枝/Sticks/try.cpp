#include <algorithm>
#include <bits/stdc++.h>
#include <vector>


bool DoableHelp(const std::vector<int>& values, int i_stick, int cur_filled, std::vector<int> used, int total_sticks, int stick_len, int last) {
    if (i_stick > total_sticks) {
        return true;
    } 
    if (cur_filled == stick_len) {
        return DoableHelp(values, i_stick + 1, 0, used,  total_sticks, stick_len, 0);
    }
    int failed = -1;
    for (int i = last; i < values.size(); ++i) {
        if (used[i]) {
            continue;
        }
        if (cur_filled + values[i] > stick_len){
            continue;
        }
       if(values[i] == failed) {
            continue;;
        }
        used[i] = 1;
        auto b = DoableHelp(values, i_stick, cur_filled + values[i], used, total_sticks, stick_len, last + 1);
        if (b) return true;
        used[i] = 0;
        failed = values[i];
        if (cur_filled == 0) return false;
        if (cur_filled + values[i] == stick_len) {
            return false;
        }
    }
    return false;

}
bool Doable(const std::vector<int>& values, int len, int sum) {
    std::vector<int> used (values.size(), 0) ;

    return DoableHelp(values, 1, 0, used, sum / len, len, 0);

} 
void Solve(std::vector<int>& values) {
    if (values.size() == 1) {
        std::cout << values[0] << std::endl;
        return;
    }
    std::sort(values.begin(), values.end());
    std::reverse(values.begin(), values.end());
    int sum = 0;
    for(int i = 0; i < values.size(); ++i) {
        sum += values[i];
    }
    for(int j = values[0]; j <= sum / 2; ++j) {
        if (sum % j == 0 && Doable(values, j, sum)) {
            std::cout << j << std::endl;
            return;
        }
    }
    std::cout << sum << std::endl;
}
int main() {
    while(true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            return 0;
        }
        std::vector<int> values;
        for (int i = 0; i < n; ++i) {
            int k;
            std::cin >> k;
            if (k <= 50)
                values.push_back(k);
        }
        Solve(values);
    }

}