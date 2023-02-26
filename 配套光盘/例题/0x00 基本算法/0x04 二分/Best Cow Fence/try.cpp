#include <bits/stdc++.h>
#include <limits>
int main() {
    int N, F;
    std::cin >> N >> F;
    std::vector<double> A(N, 0);
    double max_value = 0.0;
    for (int i = 1; i <=N; ++i) {
        std::cin >> A[i - 1];
        max_value = std::max(max_value, A[i - 1]);
    }
    double l = 0;
    double r = max_value;
    double eps = 1e-5;
    while (r -l > eps) {
        double mid = (r + l) / 2.0;
        std::vector<double> B = A;
        for (int i = 0; i < B.size(); ++i) {
            B[i] -= mid;
        }
        for (int i = 1; i < B.size(); ++i) {
            B[i] += B[i - 1] ;
        }
        double cur_min = 0.0;
        double ans = -1.0;
        for (int i = F - 1; i < N; ++i) {
            ans = B[i] - cur_min;
            if (ans >= 0) break;
            cur_min = std::min(cur_min, B[i - F + 1]);
        }
        if (ans >= 0) l = mid; else r = mid;
    }
    std::cout << int(r * 1000) << std::endl;


}