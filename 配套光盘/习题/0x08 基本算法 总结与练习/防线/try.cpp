#include <bits/stdc++.h>
#include <cstdint>
#include <limits>
#include <vector>
struct Defense {
    uint32_t start;
    uint32_t end;
    uint32_t steps;
};
uint32_t GetTotalPoints(const std::vector<Defense>& defenses, uint32_t left, uint32_t right) {
    int ans = 0;
    for (int i = 0; i < defenses.size(); ++i) {
        int a = std::max(defenses[i].start, left);
        int b = std::min(defenses[i].end, right);
        if (a <= b) {
            int x = (a - defenses[i].start) / defenses[i].steps;
            if (((a - defenses[i].start) % defenses[i].steps) != 0) {
                x = x + 1;
            }
            int y = (b - defenses[i].start) / defenses[i].steps;
            ans += y - x + 1;
        }
    }
    return ans;
}

void Solve() {
    int N;
    std::cin >> N;
    uint32_t left = std::numeric_limits<uint32_t>::max();
    uint32_t right = 0;
    std::vector<Defense> defenses(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> defenses[i].start >> defenses[i].end >> defenses[i].steps;
        left = std::min(left, defenses[i].start);
        right = std::max(right, defenses[i].end);
    }
    if (GetTotalPoints(defenses, left, right) % 2 == 0){
        std::cout << "There’s no weakness." << std::endl;
        return;
    }
    while(left < right) {
        uint32_t mid = (left + right) / 2;
        auto x = GetTotalPoints(defenses, left, mid);
        if (x % 2 == 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    std::cout << left << " " << GetTotalPoints(defenses, left, left) << std::endl;


}
int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        Solve();
    }
}