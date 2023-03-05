#include <bits/stdc++.h>
#include <cstdint>
#include <vector>

int64_t SolveOneCase(std::vector<uint64_t>& values, uint64_t m, uint64_t k) {
    int64_t ans = 0;
    int64_t l = 0;
    int64_t r = l;
    int64_t steps = 1;
    while(l < values.size()) {
        while(steps > 0) {
            steps = std::min(steps, (int64_t)values.size() - r - 1);
            if (steps == 0) break;
            std::vector<uint64_t> tmp(steps + r - l + 1, 0);
            std::vector<uint64_t> tmp2(steps, 0);
            for (int64_t i = 0; i < steps; ++i) {
                tmp2[i] = values[r + 1 + i];
            }
            std::sort(tmp2.begin(), tmp2.end());
            { //merge sorted array.
                int64_t i1 = l;
                int64_t i2 = 0;
                int64_t i3 = 0;
                while(i1 <= r && i2 < tmp2.size()) {
                    if (values[i1] <= tmp2[i2]) {
                        tmp[i3++] = values[i1++];
                    } else {
                        tmp[i3++] = tmp2[i2++];
                    }
                }
                while (i1 <= r) {
                    tmp[i3++] = values[i1++];
                }
                while(i2 < tmp2.size()) {
                    tmp[i3++] = tmp2[i2++];
                }
            }
            tmp2.clear();
            uint64_t spd = 0;
            {
                int64_t left = 0;
                int64_t right = tmp.size() - 1;
                int64_t num_pair = 0;
                while(left < right && num_pair < m && spd <= k) {
                    spd += (uint64_t)(tmp[right] - tmp[left]) * (tmp[right] - tmp[left]);
                    --right;
                    ++left;
                    ++num_pair;
                }
            }
            if (spd <= k) {
                for (int64_t i = 0; i < tmp.size(); ++i) {
                    values[l + i] = tmp[i];
                }
                r = r + steps;
                steps *= 2;
            } else {
                steps /= 2;
            }
            tmp.clear();
        }
        
        ++ans;
        l = r + 1;
        r = l;
        steps = 1;
    }
    return ans;
}

void Solve() {
    int64_t m;
    uint64_t n, k;
    std::cin >> n >> m >> k;
    std::vector<uint64_t> values(n, 0);
    for (int64_t i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    std::cout << SolveOneCase(values, m, k) << std::endl;
}
int main() {
    int64_t T;
    std::cin >> T;
    for (int64_t i = 0; i < T; ++i) {
        Solve();
    }
}