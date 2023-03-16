#include <bits/stdc++.h>
#include <limits>
struct WS {
    int64_t weight;
    int64_t strength;
};
int main() {
    int N;
    std::cin >> N;
    std::vector<WS> data(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> data[i].weight >> data[i].strength;
    }
    std::sort(data.begin(), data.end(), [](const WS& w1, const WS& w2) {
        return w1.strength + w1.weight < w2.strength + w2.weight;
    });
    int64_t ans = std::numeric_limits<int64_t>::min();
    int64_t weight_cum = 0;
    for (int i = 0; i < N; ++i) {
       ans = std::max(ans, weight_cum - data[i].strength);
       weight_cum += data[i].weight;
    }
    std::cout << ans << std::endl;

}