#include <any>
#include <bits/stdc++.h>
#include <deque>
#include <functional>
#include <utility>

std::string Solve(const std::vector<int>& values, int k, std::function<bool(int, int)> op) {
    std::deque<std::pair<int, int>> queue;
    for (int i = 0; i < k -2 ; ++i) {
        while(queue.size() && (values[i] == queue.back().second || op(values[i], queue.back().second ))) {
            queue.pop_back();
        }
        queue.push_back(std::make_pair(i, values[i]));
    }
    std::stringstream ss;
    for (int i = k - 1; i < values.size(); ++i) {
        while(queue.size() && (i - queue.front().first + 1) > k) {
            queue.pop_front();
        }
        while(queue.size() && (values[i] == queue.back().second || op(values[i], queue.back().second ))) {
            queue.pop_back();
        }
        queue.push_back(std::make_pair(i, values[i]));
        ss << queue.front().second << " ";
    }
    std::string s = ss.str();
    s.pop_back();
    return s;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> values(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    std::cout << Solve(values, k, std::less<int>()) << std::endl;
    std::cout << Solve(values, k, std::greater<int>()) << std::endl;
}
