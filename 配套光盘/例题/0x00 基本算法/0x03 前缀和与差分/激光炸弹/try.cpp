#include <bits/stdc++.h>
#include <cstring>
#include <vector>

int matrix[5006][5006];

int main() {
    int n, R;
    std::cin >> n >> R;
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < n; ++i) {
        int x, y, value;
        std::cin >> x >> y >> value;
        matrix[x][y] = value;
    }
    for (int i = 0; i <= 5000; ++i) {
        for (int j = 0; j <= 5000; ++j) {
            if (i == 0 && j == 0){ 
                continue;
            } else if (i == 0) { 
                matrix[i][j] += matrix[i][j - 1];
            } else if (j == 0) { 
                matrix[i][j] += matrix[i - 1][j];
            } else {
                matrix[i][j] += (matrix[i - 1][j] + matrix[i][j -1] - matrix[i - 1][j -1]);
            }
        }
    }
    int max_value = 0;
    if (R <= 5000) {
        for (int i = 0; i + R <= 5001; ++i) {
            for (int j = 0; j + R <= 5001; ++j) {
                int value = matrix[i + R - 1] [j + R - 1];
                if (i > 0)  value -= matrix[i - 1][j + R - 1];
                if (j > 0)  value -= matrix[i + R - 1][j - 1];
                if (i > 0 && j > 0) value += matrix[i - 1][j - 1];
                max_value = std::max(max_value, value);
            }
        }
    } else {
        max_value = matrix[5000][5000];
    }
    std::cout << max_value << std::endl;

}