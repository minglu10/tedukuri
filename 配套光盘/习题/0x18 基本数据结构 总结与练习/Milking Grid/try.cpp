#include <bits/stdc++.h>
#include <vector>
constexpr uint64_t prime = 131;
int GetMaxLen(const std::vector<uint64_t>& values) {
    std::vector<int> nxt(values.size(), 0);
    for (int i = 1; i < values.size(); ++i) {
        if (values[i] == values[nxt[i - 1]]) {
            nxt[i] = nxt[i - 1] + 1;
        } else {
            int k = nxt[i - 1];
            while(k > 0) {
                if (values[i] == values[k]) {
                    nxt[i] = k  + 1;
                    break;
                }
                k = nxt[k - 1];
            }
            if (nxt[i] == 0) {
                nxt[i] = values[i] == values[0];
            }
        }
    } 
    return values.size() - nxt.back();
}
int main() {
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> values(R);
    for (int i = 0; i < R; ++i) {
        std::string s;
        std::cin >> s;
        values[i] = s;
    }
    std::vector<uint64_t> rows(R, 0);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            rows[i] = rows[i] * prime + values[i][j];
        }
    }
    int r1 = GetMaxLen(rows);
    std::vector<uint64_t> cols(C, 0);
    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < R; ++i) {
            cols[j] = cols[j] * prime + values[i][j];
        }
    }
    int r2 = GetMaxLen(cols);
    std::cout << r1 * r2 << std::endl;

}