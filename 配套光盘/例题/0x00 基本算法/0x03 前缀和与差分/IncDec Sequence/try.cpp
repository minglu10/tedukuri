#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int64_t p,q;
    p = q = 0;
    int64_t pre = 0;
    for (int64_t i = 1; i <= n; ++i) {
        int64_t cur;
        std::cin >> cur;
        if (i > 1) {
            if (cur - pre > 0) {
                p += cur - pre;
            } else {
                q += pre -cur;
            }
        }
        pre = cur;
    }
	std::cout << std::max(p, q) << std::endl << std::abs(p - q) + 1 << std::endl;



}