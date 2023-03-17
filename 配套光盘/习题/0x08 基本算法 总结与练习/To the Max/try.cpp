#include <bits/stdc++.h>
int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> values(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> values[i][j];    
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        std::vector<int> sums(N, 0);
        for (int j = i; j < N; ++j) {
            int cum_sum = 0;
            for(int k = 0; k < N; ++k ) {
                sums[k] += values[j][k];
                cum_sum += sums[k];
                ans = std::max(ans, cum_sum);
                if (cum_sum < 0) {
                    cum_sum = 0;
                }
            }

        }
    }
    std::cout << ans << std::endl;
}