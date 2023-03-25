#include <bits/stdc++.h>
#include <cstdint>
constexpr uint64_t prime = 131;
int main() {
    std::string s;
    std:: cin >> s;
    std::vector<uint64_t> hashes(s.size() + 1, 0);
    std::vector<uint64_t> powers(s.size(), 1);
    for (int i = 0; i < s.size(); ++i) {
        powers[i + 1] = powers[i] * prime;
        hashes[i + 1] = hashes[i] * prime + (s[i] - 'a' + 1);
    }
    int n; 
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        uint64_t x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (y1 - x1 != y2 - x2){
            std::cout << "No" << std::endl;
        }
        uint64_t v1 = hashes[y1] - (hashes[x1 - 1] * powers[y1 - x1 + 1]);
        uint64_t v2 = hashes[y2] - (hashes[x2 - 1] * powers[y2 - x2 + 1]);
        if (v1 == v2) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}