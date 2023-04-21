#include <bits/stdc++.h>
#include <cstdint>
#include <deque>
#include <queue>
#include <ratio>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

void Solve(const std::deque<int64_t>& values, int m) {
    int pos_count = 0;
    int64_t cur_sum = 0;
    std::priority_queue<std::pair<int, std::pair<int, int>>> queue;
    auto hash = [](const std::pair<int, int>& key) {
        return std::hash<int>()(key.first)^ std::hash<int>()(key.second);
    };
    std::unordered_map<std::pair<int, int>, int, decltype(hash)> values_map(values.size(), hash);
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] > 0) {
            ++pos_count;
            cur_sum += values[i];
            queue.push(std::make_pair(-values[i], std::make_pair(i, i)));
        } else {
            queue.push(std::make_pair(values[i], std::make_pair(i,i)));
        }
        values_map[std::make_pair(i, i)] = values[i];
    }
    if (pos_count <= m) {
        std::cout << cur_sum << std::endl;
        return;
    }
    m = m - pos_count;
    std::unordered_map<int, int> pres;
    std::unordered_map<int, int> nexts;
    for(int i = 0; i < values.size(); i++) {
        pres[i] = i - 1;
        nexts[i] = i + 1;
    }
    std::unordered_set<int> used;
    while(m > 0) {
       const auto top = queue.top();
       queue.pop();
       if (used.count(top.second.first) || used.count(top.second.second)) {
        continue;
       }
       if (values_map.at(top.second) > 0) {
        --m;
        cur_sum -= values_map.at(top.second);
       }  else {
        auto next = nexts[top.second.second];
        auto pre = pres[top.second.first];
        if ()
       }




    }

}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::deque<int64_t> values;
    int positive = 0; 
    int64_t local_sum = 0;
    for (int i = 0; i < n; ++i) {
        int64_t k;
        std::cin >> k;
        if (k == 0) continue;;
        if (positive == 0) {
            positive = (k > 0);
            local_sum += k;
            continue;
        }
        if (k  * positive > 0) {
            local_sum +=k;
        } else {
            values.push_back(local_sum);
            local_sum = k;
            positive = -positive;
        }
    }
    values.push_back(local_sum);
    while(values.size() && values.back() <= 0) values.pop_back();
    while(values.size() && values.front() <= 0) values.pop_front();
    if (values.size() == 0) {
        std::cout << 0 << std::endl;
    }
    Solve(values, m);
}