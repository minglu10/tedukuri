#include <bits/stdc++.h>
#include <deque>
#include <stdexcept>
#include <unordered_map>
#include <vector>
int main() {
    std::array<std::deque<int>, 13> cards;
    std::unordered_map<int, int> open_cards;
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c;
            std::cin >> c;
            if (c == '0') {
                c = '0' + 10;
            } else if (c == 'J') {
                c = '0' + 11;
            } else if (c == 'Q') {
                c = '0' + 12;
            } else if (c == 'K') {
                c = '0' + 13;
            } else if (c == 'A') {
                c = '0' + 1;
            }
            cards[i].push_back(c - '0' - 1);
        }
    }
    for(int k = 0; k < 4; ++k) {
        int i = cards[12].front();
        cards[12].pop_front();
        while(i != 12) {
            open_cards[i] = open_cards[i] + 1;
            if (cards[i].empty()) {
                std::cout << "bad " << std::endl;
                break;
            }
            int i1 = cards[i].back();
            cards[i].pop_back();
            i = i1;
        }
    }
    int ans = 0;
    for (auto it : open_cards) {
        if (it.second == 4) {
            ++ans;
        }
    }
    std::cout << ans << std::endl;
}