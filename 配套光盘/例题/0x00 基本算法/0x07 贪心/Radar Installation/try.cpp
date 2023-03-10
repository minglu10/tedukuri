#include <bits/stdc++.h>
#include <cmath>
#include <limits>
struct XY {
    double x = 0;
    double y = 0;
    double x_left = 0;
    double x_right = 0;
    bool operator < (const XY& i) {
        return x_right < i.x_right;
    }
};

int main() {
    int case_n = 1;
    while(true) {
        int n, d;
        std::cin >> n >> d;
        std::vector<XY> islands(n);
        bool too_high = false;
        double dsqure = d * d;
        for (int i = 0; i < n; ++i) {
            std::cin >> islands[i].x;
            std::cin >> islands[i].y;
            auto dist = std::sqrt(dsqure - islands[i].y * islands[i].y);
            islands[i].x_left  = islands[i].x - dist;
            islands[i].x_right  = islands[i].x + dist;

            if(islands[i].y > d)
                too_high = true;

        }
        if (too_high) {
            std::cout << -1 << std::endl;
            break;
        } 
        std::sort(islands.begin(), islands.end());
        int ans = 0;
        double pre_x = std::numeric_limits<double>::lowest();
        for (const auto& island : islands) {
            if (!((island.x_left <= pre_x) && (island.x_right >= pre_x))) {
                ++ans;
                pre_x = island.x_right;
                //std::cout << pre_x << std::endl;
            }
        }
        std::cout << ans << std::endl;
        break;
        
    }

}