#include <bits/stdc++.h>
#include <cstdint>

int main() {
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> values(N, 0);
    int64_t sum = 0;
    for(int i = 0; i < N; ++i) {
        std::cin >> values[i];
        sum += values[i];
    }
    int64_t avg = sum / N;
    assert(sum % N == 0);
    for (int i = 0; i < N; ++i) {
        values[i] -= avg;
        if (i != 0) {
            values[i] += values[i - 1];
        }
    }
    std::sort(values.begin(), values.end());
    uint64_t ans = 0;
    int left = 0;
    int right = N - 1;
    while(left < right) {
        ans += values[right] - values[left];
        --right;
        ++left;
    }
    std::cout << ans << std::endl;

}