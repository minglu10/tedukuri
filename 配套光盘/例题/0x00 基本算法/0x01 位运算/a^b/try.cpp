#include <bits/stdc++.h>
#include <cstdint>
int pow(int a, int b, int p) {
    int ans = 1 % p;
    while(b > 0) {
        if (b & 1) {
            ans = (uint64_t)a * ans %p;
        }
        a = (uint64_t)a * a % p;
        b = (b >> 1);
    }
    return ans;

}

int main() {
    int a, b, p;
    std::cin >> a >> b >> p;
    std::cout << pow(a, b, p) << std::endl;

}