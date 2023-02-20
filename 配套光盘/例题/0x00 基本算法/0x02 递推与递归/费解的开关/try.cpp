#include <bits/stdc++.h>
#include <limits>
void flip(int matrix[5][5], int row, int col) {
    if (row - 1 >= 0) {
        matrix[row - 1][col] ^= 1;
    }
    matrix[row][col] ^= 1;
    if(row + 1 < 5) {
        matrix[row + 1][col] ^= 1;
    }
    if (col - 1 >= 0) {
        matrix[row][col - 1] ^= 1;
    }
    if (col + 1 < 5) {
        matrix[row][col + 1] ^= 1;
    }

}

int solve(int matrix_org[5][5]) {
    int total_number = std::numeric_limits<int>::max();
    int matrix[5][5];
    for (int first_row_flips = 0; first_row_flips < 32; ++first_row_flips) {
        memcpy(matrix, matrix_org, 5 * 5 * sizeof(int));
        int count = 0;
        for (int col = 0; col <5; ++col) {
            if ((first_row_flips >> col)& 1) { //flip
                ++count;
                flip(matrix, 0, col);
            }
        }
        for (int row = 1; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (matrix[row -1][col] == 0) {
                    ++count;
                    flip(matrix, row, col);
                }
            }
        }
        bool good = true;
        for (int col = 0; col < 5; ++col) {
            if (matrix[4][col] == 0) {
                good = false;
                break;
            }
        }
        if (good) {
            total_number = std::min(total_number, count);
        }
    }
    if (total_number > 6) {
        return -1;
    }
    return total_number;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <=n; ++i) {
        int matrix[5][5];
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                char c ;
                std::cin >> c;
                matrix[row][col] = c - '0';
            }
        }
        int flips = solve(matrix);
        std::cout << flips << std::endl;
    }

}