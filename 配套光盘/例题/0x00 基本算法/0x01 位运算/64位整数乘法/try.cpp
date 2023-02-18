#include <bits/stdc++.h>
#include <cstdint>
#include <stdexcept>

std::uint64_t mul(std::uint64_t a, std::uint64_t b, std::uint64_t p) {
    std::uint64_t ans = 0;
    while (b > 0) {
        if (b & 1) {
            ans += a;
            ans %= p;
        } 
        a = a * 2 % p;
        b = (b >> 1);
    }
    return ans;

}
int main() {
    uint64_t a, b, p;
	std:: cin >> a >> b >> p;
	std::cout << mul(a, b, p) << std::endl;
}