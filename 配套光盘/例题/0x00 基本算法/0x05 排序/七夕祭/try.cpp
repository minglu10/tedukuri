#include <boost/unordered/unordered_flat_map.hpp>
#include <bits/stdc++.h>
#include <cassert>

int64_t getSteps(std::vector<int64_t>& a, int64_t k) {
    for(int64_t i = 0; i < a.size(); ++i) {
        a[i] -= k / a.size();
    }
    for (int64_t i = 1; i < a.size(); ++i) {
        a[i] += a[i - 1];
    }
    assert(a.back() == 0);
    std::sort(a.begin(), a.end());
    int64_t left = 0;
    int64_t right = a.size() - 1;
    int64_t ans = 0;
    while (left <= right) {
        ans += a[right] - a[left];
        ++left;
        --right;
    }
    return ans;

}

int main() {
    boost::unordered::unordered_flat_map<int64_t, int64_t> test_boost;
    test_boost[5] = 65;
    int64_t m, n, k;
    std::cin >> m >> n >> k;
    std::vector<int64_t> rows(m, 0);
    std::vector<int64_t> cols(n, 0);
    for (int64_t i = 0; i < k; ++i) {
        int64_t x, y;
        std::cin >> x >> y;
        ++rows[x - 1];
        ++cols[y - 1];
    }
    if ((k % m != 0) && (k % n != 0)) {
        std::cout << "imposible\n";
        return 0;
    } else if ((k %m == 0) && (k %n == 0)) {
        std::cout << "both ";
    } else if (k %m == 0) {
        std::cout << "row ";
    } else if (k % n == 0) {
        std::cout << "column ";
    }
    int64_t steps = 0;
    if (k % m == 0) {
        steps += getSteps(rows, k);
    }
    if (k % n == 0) {
        steps += getSteps(cols, k);
    }
    std::cout << steps << std::endl;

}