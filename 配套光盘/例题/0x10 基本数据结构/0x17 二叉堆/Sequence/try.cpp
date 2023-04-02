#include <bits/stdc++.h>
#include <cstdint>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>


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
    }
    std::priority_queue<std::pair<int64_t, std::vector<int>>> queue;
    std::set<std::vector<int>> used;
    int64_t sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += values[i][0];
    }
    std::vector<int>index(m, 0);
    queue.emplace(std::make_pair(-sum, index));
    used.insert(index);
    std::vector<int64_t> ans_values;
    while(ans_values.size() < n) {
        auto & t = queue.top();
        ans_values.push_back(-t.first);
        index = std::move(t.second);
        queue.pop();
        for (int i = 0; i < m ; ++i) {
            auto index1 = index;
            index1[i] += 1;
            if (used.count(index1) == 0) {
                sum = 0;
                for (int j = 0; j < m; ++j) {
                    sum += values[j][index1[j]];
                }
                queue.emplace(std::make_pair(-sum, index1));
                used.insert(index1);
            }
        }
        
    }
    std::stringstream ss;
    for (int i = 0; i < n; ++i) {
        ss << ans_values[i] << " ";
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