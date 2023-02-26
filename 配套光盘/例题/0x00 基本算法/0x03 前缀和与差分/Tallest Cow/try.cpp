#include <bits/stdc++.h>
#include <utility>
std::set<std::pair<int, int>> visited;
int main () {
    int N, I, H, R;
    std::cin >> N >> I >> H >> R;
    std::vector<int> diff(N + 2, 0);
    for (int i = 1; i <= R; ++i) {
        int a, b;
        std::cin >> a >> b;
        if (a==b) continue;
        if (a > b) std::swap(a, b);
        auto v = std::make_pair(a, b) ;
        if (visited.count(v)) continue;
        visited.insert(v);
        diff[a + 1] -= 1;
        diff[b] += 1;
    }
    int cum = 0;
    for (int i = 1; i <= N; ++i) {
        cum += diff[i];
        std::cout << H + cum << std::endl;
    }
}