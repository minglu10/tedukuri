#include <bits/stdc++.h>
#include <cstdint>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

std::vector<int64_t> Merge(std::vector<int64_t>& v1, std::vector<int64_t>& v2) {
    std::unordered_map<int, std::set<int>> used;
    std::priority_queue<std::vector<int64_t>> queue;
    std::vector<int64_t> v3;
    queue.push(std::vector<int64_t>{-v1[0]-v2[0], 0, 0});
    used[0].insert(0);
    while(v3.size() < v1.size()) {
        const auto& t = queue.top();
        int i = t[1];
        int j = t[2];
        v3.push_back(-t[0]);
        queue.pop();
        if (used[i + 1].count(j) == 0) {
            used[i + 1].insert(j);
            queue.push(std::vector<int64_t>{-v1[i +1] - v2[j], i + 1, j});
        }
        if (used[i].count(j + 1) == 0) {
            used[i].insert(j + 1);
            queue.push(std::vector<int64_t>{-v1[i] - v2[j + 1], i, j + 1});
        }
    }
    return v3;
}

void Solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int64_t>> values;
    for (int i = 0; i < m; ++i) {
        std::vector<int64_t> vs(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> vs[j];
        }
        std::sort(vs.begin(), vs.end());
        values.emplace_back(std::move(vs));
        if (values.size() > 1) {
            auto v = Merge(values[0], values[1]);
            values.clear();
            values.emplace_back(std::move(v));
        }
    }
    std::stringstream ss;
    for (int i = 0; i < n; ++i) {
        ss << values[0][i] << " ";
    }
    std::string s = ss.str();
    s.pop_back();
    std::cout << s << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        Solve();
    }


}