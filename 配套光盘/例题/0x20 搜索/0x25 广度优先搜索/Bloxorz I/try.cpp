#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

void bfs(const std::vector<std::string>& values, std::pair<int, int>& start, std::pair<int, int>& end) {
    std::vector<int> start_pos{start.first, start.second, 0};
    auto hash =[](const std::vector<int>& v)->size_t {
       size_t ans = 0;
       for (const auto i : v) {
        ans^=std::hash<int>()(i);
       } 
       return ans;

    };
    std::unordered_set<std::vector<int>, decltype(hash)> used(10, hash);
    std::vector<std::vector<int>> cur_queue;
    std::vector<std::vector<int>> next_queue;
    cur_queue.push_back(start_pos);
    while(cur_queue.size()) {
        
    }
}

void Solve(const std::vector<std::string>& values) {
    std::pair<int, int> start{-1, -1};
    std::pair<int, int> end{-1, -1};
    int R = values.size();
    int C = values[0].size();
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (values[i][j] == 'O') {
                end = std::make_pair(i, j);
            } else if (values[i][j] == 'X') {
                start = std::make_pair(i, j);
            }
        }
    }
    bfs(values, start, end);
}

int main() {
    while(true) {
        int R, C;
        std::cin >> R >> C;
        if (R == 0 || C == 0) {
            return 0;
        }
        std::vector<std::string> values(R, "");
        for(int i = 0; i < R; ++i) {
            std::cin >> values[i];
        }
        Solve(values);
    }
}