#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <vector>
struct Cow {
    int64_t _minspf;
    int64_t _maxspf;
    bool operator < (const Cow& c1) {
        return _maxspf < c1._maxspf;
    }
};
int main() {
    std::map<int64_t, int64_t> lotions;
    int64_t C, L;
    std::cin >> C >> L;
    std::vector<Cow> cows(C);
    for (int64_t i = 0; i < C; ++i) {
        std::cin >> cows[i]._minspf; 
        std::cin >> cows[i]._maxspf; 
    }
    std::sort(cows.begin(), cows.end());
    for (int64_t i = 0; i < L; ++i) {
        int64_t s, n;
        std::cin >> s >> n;
        lotions[s] += n;
    }
    int64_t ans = 0;
    for (const auto& cow : cows) {
        auto it = lotions.lower_bound(cow._minspf);
        if (it == lotions.end()) {
            continue;
        }
        if (cow._maxspf < it->first) {
            continue;
        }
        --it->second;
        ++ans;
        if (it->second == 0) {
            lotions.erase(it);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}