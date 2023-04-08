#include <bits/stdc++.h>
#include <cstdint>
#include <unordered_map>
#include <vector>
constexpr uint64_t col_p = 131;
constexpr uint64_t row_p = 231;
int main() {
    int M, N, A, B;
    std::cin >> M >> N >> A >> B;
    std::vector<std::vector<uint64_t>> values(M + 1, std::vector<uint64_t>(N + 1, 0));
    for (int i = 1; i <= M; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= N; ++j) {
            values[i][j] = s[j - 1] - '0';
            values[i][j] += values[i][j -1] * col_p;
        }
    }
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            values[i][j] += values[i -1][j] * row_p;
        }
    }
    std::vector<uint64_t> power_cols(N + 1, 1);
    for (int i = 1; i <=N; ++i) {
        power_cols[i] = power_cols[i - 1] * col_p;
    }
    std::vector<uint64_t> power_rows(M + 1, 1);
    for (int i = 1; i <= M; ++i) {
        power_rows[i] = power_rows[i - 1] * row_p;
    }
    std::unordered_set<uint64_t> hash_values;
    for (int i = A; i <= M; ++i) {
        for (int j = B; j <= N; ++j) {
            hash_values.insert(values[i][j] + values[i - A][j - B] * power_rows[A] * power_cols[B] - values[i - A][j] * power_rows[A] - values[i][j - B] * power_cols[B]);
        }
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::vector<std::vector<uint64_t>> values_ab(A + 1, std::vector<uint64_t>(B + 1, 0));
        for (int i = 1; i <= A; ++i) {
            std::string s;
            std::cin >> s;
            for (int j = 1; j <= B; ++j) {
                values_ab[i][j] = s[j - 1] - '0';
                values_ab[i][j] += values_ab[i][j -1] * col_p;
            }
        }
        for (int i = 1; i <= A; ++i) {
            for (int j = 1; j <= B; ++j) {
                values_ab[i][j] += values_ab[i -1][j] * row_p;
            }
        }
        if (hash_values.count(values_ab[A][B]) > 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }

    }

}