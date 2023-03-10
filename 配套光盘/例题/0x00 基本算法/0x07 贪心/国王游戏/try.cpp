#include <bits/stdc++.h>
#include <cstdint>
#include <limits>
#include <unordered_map>
#include <utility>
int main() {
    int n;
    std::cin >> n;
    int left_king, right_king;
    std::cin >> left_king >> right_king;
    std::unordered_map<int, std::pair<int, int>> officials;
    std::vector<std::pair<double, int>> products;
    for (int i = 0; i < n ; ++i) {
        int a, b;
        std::cin >> a >> b;
        officials[i] = std::make_pair(a, b);
        double d = (double) a * b;
        products.push_back(std::make_pair(d, i));
    }
    std::sort(products.begin(), products.end());
    double accu = left_king;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        double pay = accu / officials[products[i].second].second;
        ans = std::max(ans, pay);
        accu *= officials[products[i].second].first;
    }
    std::cout << ans << std::endl;
}