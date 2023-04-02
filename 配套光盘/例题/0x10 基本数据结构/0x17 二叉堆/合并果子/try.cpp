#include <bits/stdc++.h>
#include <cstdint>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::priority_queue<int64_t> pri_queue;
    for (int i = 0; i < n; ++i) {
        int64_t k;
        std::cin >> k;
        pri_queue.push(-k);
    }
    int64_t ans = 0;
    while(pri_queue.size() > 1) {
        auto top1 = pri_queue.top();
        pri_queue.pop();
        auto top2 = pri_queue.top();
        pri_queue.pop();
        auto sum = top1 + top2;
        ans += sum;
        pri_queue.push(sum);
    }
    std::cout << -ans << std::endl;
}