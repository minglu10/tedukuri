#include <bits/stdc++.h>
#include <limits>
int main() {
    int h3[16];
    h3[0] = 0;
    h3[1] = 1;
    for (int i = 2; i < sizeof(h3) / sizeof(h3[0]); ++i) {
        h3[i] = 2 * (h3[i - 1]) + 1;
    }
    int h4[16];
    h4[0] = 0;
    h4[1] = 1;
    for (int i = 2; i < sizeof(h4) / sizeof(h4[0]); ++i) {
       int min_value = std::numeric_limits<int>::max(); 
       for (int j = 1; j <= i - 1; ++j) {
            min_value = std::min(min_value, 2 * h4[j] + h3[i - j]);
       }
       h4[i] = min_value;
    }
    for (int i = 0; i < sizeof(h4) / sizeof(h4[0]); ++i) {
        std::cout << h4[i] << std::endl;
    }
    

}