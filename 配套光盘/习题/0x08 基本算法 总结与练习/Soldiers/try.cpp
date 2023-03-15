#include <bits/stdc++.h>
struct XY {
    int64_t x = 0;
    int64_t y = 0;
};

int main() {
    int64_t N;
    std::cin >> N;
    std::vector<XY> xys(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> xys[i].x >> xys[i].y;
    }
    std::sort(xys.begin(), xys.end(), [](const XY& p1, const XY& p2) {return p1.y < p2.y;});
    int64_t ans = 0;
    int left = 0; 
    int right = N - 1;
    while(left < right) {
        ans += xys[right].y - xys[left].y;
        --right;
        ++left;
    }
    std::sort(xys.begin(), xys.end(),  [](const XY& p1, const XY&p2) {return p1.x < p2.x;});
    for(int i = 0; i < xys.size(); ++i) {
        xys[i].x -= i;
    }
    std::sort(xys.begin(), xys.end(),  [](const XY& p1, const XY&p2) {return p1.x < p2.x;});
    left = 0;
    right = N - 1;
    while(left < right) {
        ans +=xys[right].x - xys[left].x;
        --right;
        ++left;
    }
    std::cout << ans << std::endl;


}