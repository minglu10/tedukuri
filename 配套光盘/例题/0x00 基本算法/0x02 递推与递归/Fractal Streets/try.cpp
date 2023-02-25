#include <any>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
#include <utility>
struct XY{
    uint64_t _x = 0;
    uint64_t _y = 0;

};
XY getCoordinates(uint64_t N, uint64_t A) {
    if (N == 0) {
        return XY {._x = 0, ._y = 0};
        
    }
    uint64_t quart = (A - 1) / ((uint64_t)1 << (2 *N - 2));
    uint64_t A1 = A - quart * ((uint64_t)1 << (2 * N -2));
    auto [prex, prey] = getCoordinates(N - 1, A1);
    uint64_t offset = (uint64_t)1 << (N - 1);
    switch (quart) {
        case 0:
            return XY {._x = prey, ._y = prex};
        case 1:
            return XY {._x = prex, ._y = prey + offset};
        case 2: {
            return XY {._x = prex + offset, ._y = prey + offset};
        }
        case 3: {
            uint64_t prex2 = (offset - 1) - prex;
            uint64_t prey2 = (offset - 1) - prey;
            return XY{._x = prey2 + offset, ._y = prex2};
        }
    
    }
}
void solve(uint64_t N, uint64_t A, uint64_t B) {
    XY axy = getCoordinates(N, A);
    XY bxy = getCoordinates(N, B);
    printf("%.0f\n", (double)10*std::sqrt((axy._x - bxy._x) * (axy._x - bxy._x) +  (axy._y - bxy._y) * (axy._y - bxy._y)));

}
int main() {
    uint64_t T;
    std::cin >> T;
    for (uint64_t i = 0; i < T; ++i) {
        uint64_t N, A, B;
        std::cin >> N >> A >> B;
        solve(N, A, B);
    }


}