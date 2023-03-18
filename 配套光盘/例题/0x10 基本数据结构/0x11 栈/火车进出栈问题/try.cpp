#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<uint64_t> values(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        uint64_t ans = 0;
        for (int k = 1; k <= i; ++k) {
            ans += values[k - 1] * values[i - k];
        }
        values[i] = ans;
    }
    std::cout << values.back() << std::endl;

}