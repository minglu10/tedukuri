#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<uint64_t> aa(n, 0);
    for (int i = 0; i < aa.size(); ++i) {
        int c;
        std::cin >> c;
        aa[i] = c;
    }
    std::sort(aa.begin(), aa.end());
    uint64_t ans = 0;
    int left = 0;
    int right = aa.size() - 1;
    while(left <= right) {
        ans += (aa[right] - aa[left]);
        ++left; -- right;
    }
    std::cout << ans << std::endl;
}