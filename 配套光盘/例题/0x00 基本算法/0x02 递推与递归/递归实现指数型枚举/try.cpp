#include<vector>
#include <bits/stdc++.h>
void calc(int cur, int total, std::vector<int>&cur_result) {
    if (cur > total) {
        for (int c : cur_result) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        return;
    }
    calc(cur + 1, total, cur_result);
    cur_result.push_back(cur);
    calc(cur + 1, total, cur_result);
    cur_result.pop_back();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> cur_result;
    calc(1, n, cur_result);

}