#include <bits/stdc++.h>
#include <deque>
#include <utility>
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int64_t> values(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        std::cin >> values[i];
        values[i] += values[i - 1];
    }
    int64_t ans = values[0];
    std::deque<std::pair<int64_t, int>> stack;
    stack.push_back(std::make_pair(values[0],0));
    for (int i = 1; i <= n; ++i) {
        while(i - stack.front().second > m) {
            stack.pop_front();
        }
        ans = std::max(ans, values[i] - stack.front().first);
        while(stack.size() && stack.back().first >= values[i]) {
            stack.pop_back();
        }
        stack.push_back(std::make_pair(values[i],i));
    }
    std::cout << ans << std::endl;

}