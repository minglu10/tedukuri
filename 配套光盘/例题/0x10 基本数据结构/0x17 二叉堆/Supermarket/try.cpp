#include <bits/stdc++.h>
#include <functional>
#include <queue>

void Solve(int n) {
    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }
    std::vector<std::vector<int>> products(n);
    for (int i = 0; i < n ; ++i) {
        int price, expiry;
        std::cin >> price >> expiry;
        products[i].push_back(expiry);
        products[i].push_back(price);
    }
    std::sort(products.begin(), products.end());
    std::priority_queue<int > queue;
    for (int i = 0; i < n; ++i) {
        if (products[i][0] > queue.size()) {
            queue.push(-products[i][1]);
        } else {
            if (queue.top() > (-products[i][1])) {
                queue.pop();
                queue.push(-products[i][1]);
            }
        }
    }
    uint64_t ans = 0;
    while(queue.size()) {
        ans -= queue.top();
        queue.pop();
    }
    std::cout << ans << std::endl;

}

int main() {
    int n;
    while(std::cin >> n) {
        Solve(n);
    }

}