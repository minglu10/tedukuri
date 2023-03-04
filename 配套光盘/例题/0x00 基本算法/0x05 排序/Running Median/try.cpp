#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include "boost/unordered/unordered_flat_map.hpp"
void solve() {
    int set_n, N;
    std::cin >> set_n >> N;
    std::vector<int> values(N, 0);
    for (int i = 0; i < values.size(); ++i) {
        std::cin >> values[i];
    }
    std::priority_queue<int, std::vector<int>, std::less<int>> high_priority;
    std::priority_queue<int, std::vector<int>, std::greater<int>> low_priority;
    std::cout << set_n << " " << N / 2 + N % 2 << std::endl;;
    std::vector<int> mediums;
    for (int i = 0; i < values.size(); ++i) {
        if (low_priority.empty() || values[i] >= low_priority.top()) {
            low_priority.push(values[i]);
        } else {
            high_priority.push(values[i]);
        }
        if (low_priority.size() > 0 && low_priority.size() - 1 > high_priority.size()){
            int k = low_priority.top();
            low_priority.pop();
            high_priority.push(k);
        } else if (high_priority.size() > 0 &&  high_priority.size() - 1 > low_priority.size()) {
            int k = high_priority.top();
            high_priority.pop();
            low_priority.push(k);
        }
        if ((low_priority.size() + high_priority.size()) & 0x1) {
            if (low_priority.size() > high_priority.size()) {
                mediums.push_back(low_priority.top());
            } else {
                mediums.push_back(high_priority.top());
            }
            if (mediums.size() == 10) {
                std::cout << mediums[0];
                for (int i = 1; i < mediums.size(); ++i) {
                    std::cout << " " << mediums[i];
                }
                std::cout << std::endl;
                mediums.clear();
            }
        }
    }
    if (mediums.size() > 0) {
        std::cout << mediums[0];
        for (int i = 1; i < mediums.size(); ++i) {
            std::cout << " " << mediums[i];
        }
        std::cout << std::endl;
    } 

}

int main() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve();
    }
}