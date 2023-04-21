#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <vector>
void dfs(const std::vector<int64_t>& weights, int idx, std::vector<int64_t>& carts, const int w, int64_t& ans) {
    if (carts.size() >= ans) return;
    if(idx >= weights.size()) {
        ans = std::min(ans, (int64_t)carts.size());
        return;
    }
    for (int i = 0; i < carts.size(); ++i) {
        if (weights[idx] + carts[i] <= w) {
            carts[i] += weights[idx];
            dfs(weights, idx + 1, carts, w, ans);
            carts[i] -= weights[idx];
        }
    }
    carts.push_back(weights[idx]);
    dfs(weights, idx + 1, carts, w, ans);
    carts.pop_back();
}
int main() {
    int n, w;
    std::cin >> n >> w;
    std::vector<int64_t> weights(n, 0); 
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }
    std::sort(weights.begin(), weights.end());
    std::reverse(weights.begin(), weights.end());
    int64_t ans = std::numeric_limits<int64_t>::max();
    std::vector<int64_t> carts;
    dfs(weights, 0, carts, w, ans);
    std::cout << ans << std::endl;
}