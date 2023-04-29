#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <vector>
uint64_t W, N;
std::set<uint64_t> GetSums(std::vector<uint64_t>& vals) {
    std::sort(vals.begin(), vals.end(), std::greater<uint64_t>());
    int size = vals.size();
    uint64_t max_val = 1 << size;
    std::set<uint64_t> ans;
    for (uint64_t k = 0; k < max_val; ++k) {
        uint64_t temp = 0;
        for (int j = 0; j < size; ++j) {
            if ((k >> j) & 1) {
                temp += vals[j];
            }
            if (temp > W) {
                break;
            }
        }
        if (temp < W) ans.insert(temp);
    }
    return ans;
}
int main() {
    std::cin >> W >> N;
    std::vector<uint64_t> vals1;
    std::vector<uint64_t> vals2;
    for (int i = 0; i < N / 2; ++i) {
        int k;
        std::cin >> k;
        vals1.push_back(k);
    }
    for (int i = N / 2; i < N ; ++i) {
        int k;
        std::cin >> k;
        vals2.push_back(k);
    }
    auto sums1 = GetSums(vals1);
    auto sums2 = GetSums(vals2);
    int ans = 0;
    for (auto v : sums1) {
        uint64_t v1 = W - v;
        auto it = sums2.upper_bound(v1);
        if (it == sums2.begin()) continue;
        --it;
        int v2 = v + (*it);
        ans = std::max(ans, v2);
    }
    std::cout << ans << std::endl;
}