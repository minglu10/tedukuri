#include <bits/stdc++.h>
#include <cstdint>
#include <utility>
uint64_t PopBack(std::vector<std::pair<uint64_t, uint64_t>>& stack, uint64_t x, uint64_t i) {
    uint64_t ans = 0;
    uint64_t last_i = i;
    while(stack.size() && stack.back().first >= x) {
        ans = std::max(ans, (i - stack.back().second) * stack.back().first);
        last_i = stack.back().second;
        stack.pop_back();
    }
    stack.push_back(std::make_pair(x, last_i));
    
    return ans;

}

void Solve(uint32_t n) {
    uint64_t ans = 0;
    std::vector<std::pair<uint64_t, uint64_t>> stack;
    for (uint32_t i = 1; i <= n; ++i) {
        uint64_t x;
        std::cin >> x;
        ans = std::max(ans, PopBack(stack, x, i));
    }
    ans = std::max(ans, PopBack(stack, 0, n + 1));
    std::cout << ans << std::endl;
}

int main() {
    while(true) {
        int n;
        std::cin >> n;
        if (n == 0) break;
        Solve(n);
    }
}