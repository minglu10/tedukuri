#include <bits/stdc++.h>
#include <limits>
#include <vector>
int hamilton(const std::vector<std::vector<int>> & paths) {
    int n = paths.size();
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < (1<<n); ++i) {
        ans.emplace_back(std::vector<int>(n, std::numeric_limits<int>::max()));
    }
    ans[1][0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
    //for (int i= (1 << n); i >=0; --i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                int new_inx = i ^ (1 << j);
                for (int k = 0; k < n; ++k) {
                    if (new_inx >> k & 1) {
                        if (ans[new_inx][k] != std::numeric_limits<int>::max()) {
                            ans[i][j] = std::min(ans[i][j], ans[new_inx][k] + paths[k][j]);
                        }
                    }

                }
            }
        }
    }
    return ans[(1 << n) - 1][n-1];


}
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> paths; 
    paths.resize(n);
    for (int i = 0; i < n; ++i) {
        paths[i] = std::vector<int>(n, 0);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int k;
            std::cin >> k;
            paths[i][j] = k;
        }
    }
    std::cout << hamilton(paths) << std::endl;

}