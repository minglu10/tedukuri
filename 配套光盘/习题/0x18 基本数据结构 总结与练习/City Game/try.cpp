#include <bits/stdc++.h>
#include <utility>
#include <vector>
int64_t GetMaxArea(const std::vector<int>& vals) {
    std::vector<std::pair<int, int>> stack;
    std::vector<int> values = vals;
    values.push_back(0);
    stack.push_back(std::make_pair(-1, 0));
    int64_t ans = 0;
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] > stack.back().first) {
            stack.push_back(std::make_pair(values[i], i + 1));
        } else {
            int k = 0;
            while (stack.back().first >= values[i]) {
                k = stack.back().second;
                int h = stack.back().first;
                stack.pop_back();
                ans = std::max(ans , int64_t(i + 1 - k) * h);
            }
            stack.push_back(std::make_pair(values[i], k));
        }
    } 
    return ans;
}

int main() {
    int m, n; 
    std::cin >> m >> n;
    std::vector<int> height(n, 0);
    int64_t ans = 0;
    for (int row = 0; row < m; ++row) {
        for (int i = 0; i < n; ++i) {
            char c;
            std::cin >> c; 
            if (c == 'R') {
                height[i] = 0;
            } else {
                height[i] += 1;
            }
        }
        ans = std::max(ans, GetMaxArea(height));
    }
    std::cout << ans * 3 << std::endl;
    

}