#include <bits/stdc++.h>
#include <string>
std::string GetMinRotate(const std::string& orig) {
    std::string s = orig + orig;
    int i = 0;
    int j = 1;
    int n = orig.size();
    while(i < n && j < n) {
        int k = 0;
        for (k = 0; k < n; ++k) {
            if (s[i + k] != s[j + k]) {
                break;
            }
        }
        if (k == n) break;
        if (s[i + k] > s[j + k]) {
            i = i + k + 1;
            if (i == j) { 
                ++i;
            }
        } else {
            j = j + k  + 1;
            if (i == j) {
                ++j;
            }
        }
    }
    int k = std::min(i, j);
    return s.substr(k, n);
}
int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1.size() != s2.size()) {
        std::cout << "No" << std::endl;
        return 0;

    }
    auto s3 = GetMinRotate(s1);
    auto s4 = GetMinRotate(s2);
    if (s3 == s4) {
        std::cout << "Yes" << std::endl;
        std::cout << s3 << std::endl;
    } else {
        std::cout << "No" << std::endl;

    }

}