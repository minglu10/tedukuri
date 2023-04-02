#include <bits/stdc++.h>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> values(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    auto hash = [](const std::vector<int64_t>& val)->size_t {
        return (val[0] + 27734561) * val[1];

    };

    //std::map<std::vector<int64_t>, int64_t> distance_map;
    std::unordered_map<std::vector<int64_t>, int64_t, decltype(hash)> distance_map(n, hash);
    std::priority_queue<std::vector<int64_t>> pri_queue;
    for (int i = 1; i < values.size(); ++i) {
        pri_queue.push(std::vector<int64_t>{-(values[i] - values[i - 1]), i - 1, i});
        distance_map[std::vector<int64_t>{i -1, i}] = values[i] - values[i - 1];
    }

    std::unordered_map<int64_t, int64_t> pre_values;
    for (int i = 1; i < values.size(); ++i) {
        pre_values[i] = i - 1;
    }
    std::unordered_map<int64_t, int64_t> after_values;
    for (int i = 0; i < values.size() - 1; ++i) {
        after_values[i] = i + 1;
    }

    //std::unordered_map<int64_t, std::unordered_set<int64_t>> used;
    std::unordered_set<int64_t> used;
    
    std::vector<int64_t> ans;
    while(ans.size() < k) {
       assert(pri_queue.size());
       const auto &top = pri_queue.top();
       int64_t x = top[1];
       int64_t y = top[2];
       int64_t val = top[0];
       assert(x < y);
       pri_queue.pop();
       if (used.count(x) || used.count(y)) {
        continue;
       }
       ans.push_back(val);
       //std::cout << -val << std::endl;
       used.insert(x);
       used.insert(y);
       if (pre_values.count(x) && after_values.count(y)){
            int64_t x1 =  pre_values.at(x);
            int64_t y1 =  after_values.at(y);
            int64_t dist = distance_map.at(std::vector<int64_t>{x1, x}) +  distance_map.at(std::vector<int64_t>{y, y1}) - (-val);
            assert(dist > 0);
            pri_queue.push(std::vector<int64_t>{-dist, x1, y1});
            after_values[x1] = y1;
            pre_values[y1] = x1;
            distance_map[std::vector<int64_t>{x1, y1}] = dist;
       }
    }
    int64_t sum = 0;
    for (int64_t i : ans) {
        sum += i;
    }
    std::cout << -sum << std::endl;


}