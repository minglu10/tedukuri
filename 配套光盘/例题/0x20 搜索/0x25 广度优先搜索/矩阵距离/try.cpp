#include <bits/stdc++.h>
#include <queue>
#include <sstream>
#include <utility>
#include <vector>

void Solve(const std::vector<std::string>& values) {
    std::vector<std::vector<int>> dist(values.size(), std::vector<int>(values[0].size(), -1));
    std::queue<std::pair<int, int>> cur_queue;
    std::queue<std::pair<int, int>> nxt_queue;
    for(int i = 0; i < values.size(); ++i) {
        for (int j = 0; j < values[0].size(); ++j){
            if(values[i][j] == '1') {
                dist[i][j] = 0;
                cur_queue.push(std::make_pair(i, j));
            }
        }
    }
    const int N = values.size();
    const int M = values[0].size();
    int level = 0;
    auto add_new_point = [&nxt_queue, &dist, N, M, &level](int x1, int y1) {
        if (x1 < N && x1 >= 0 && y1 < M && y1 >=0 && dist[x1][y1] == -1) {
            dist[x1][y1] = level + 1;
            nxt_queue.push(std::make_pair(x1, y1));
        }
    };
    while(cur_queue.size() > 0) {
        while(cur_queue.size() > 0) {
            auto pos = cur_queue.front();
            cur_queue.pop();
            int x1 = pos.first - 1;
            int y1 = pos.second;
            add_new_point(x1, y1);

            x1 = pos.first + 1;
            y1 = pos.second;
            add_new_point(x1, y1);

            x1 = pos.first;
            y1 = pos.second - 1;
            add_new_point(x1, y1);

            x1 = pos.first;
            y1 = pos.second + 1;
            add_new_point(x1, y1);
        }
        ++level;
        std::swap(cur_queue, nxt_queue);
    }
    for (int i = 0; i < N; ++i) {
        std::stringstream ss;
        for (int j = 0; j < M; ++j) {
            ss << dist[i][j] << " ";
        }
        std::string s = ss.str();
        s.pop_back();
        std::cout << s <<  std::endl;
    }

}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> values(N, "");
    for (int i = 0; i < N; ++i) {
        std::cin >> values[i];
        assert(values[i].size() == M);
    }
    Solve(values);
}