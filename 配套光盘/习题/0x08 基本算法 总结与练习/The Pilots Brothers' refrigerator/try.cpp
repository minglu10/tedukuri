#include <bits/stdc++.h>
#include <limits>
int Solve(int v[4][4]) {

    int ans = std::numeric_limits<int>::max();

    for(int i = 0; i < (1 << 16); ++i) {
        int k = 0;
        std::vector<std::vector<int>> val(4, std::vector<int>(4, 0));
        for (int b = 0; b < 16 ; ++b) {
            if ((i >> b) & 0x1) {
                ++k;
                int x = b / 4;
                int y = b % 4;
                for (int k1 = 0; k1 < 4; ++k1) {
                    val[x][k1] ^= 1;
                }
                for (int k1 = 0; k1 < 4; ++k1) {
                    if (k1 != x) {
                        val[k1][y] ^= 1;
                    }
                }
            }
        }
        bool has_1 = false;
        for (int x = 0; x < 4; ++x) {
            for (int y = 0; y < 4; ++y) {
                if (v[x][y] ^ val[x][y]) {
                    has_1 = true;
                    break;
                }

            }
            if (has_1 == true) break;
        }
        if (has_1 == false) {
            ans = std::min(ans, k);
        }

    }
    return ans;

}

int main() {
    int v[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c;
            std::cin >> c;
            if (c == '+') {
                v[i][j] = 1;
            } else if (c == '-') {
                v[i][j] = 0;
            } else {
                std::cout << "bad" << std::endl;
            }
        }
    }
    int n = Solve(v);
    std::cout << n << std::endl;
}