#include <bits/stdc++.h>
#include <limits>
#include <unordered_map>
#include <vector>
int main() {
    int m, n;
    std::cin >> m;
    std::cin >> n;
    std::vector<int> values(m, 0);
    for (int i = 0; i < m; ++i) {
        std::cin >> values[i];
    }
    std::unordered_map<int, int> queries;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        queries[k] += 1;
    }
    std::map<int, int> tree;
    tree[std::numeric_limits<int>::max()] = 1;
    auto it = tree.begin();
    int sub_index = 0;
    for (int i = 0; i < values.size(); ++i) {
        tree[values[i]] += 1;
        if (values[i] < it->first) {
            --sub_index;
            if (sub_index < 0) {
                --it;
                sub_index = it->second - 1;
            } 
        } 

        if (queries.count(i + 1)) {
            for (int j = 0; j < queries.at(i + 1); j++) {
                std::cout << it->first << std::endl;
                sub_index += 1;
                if (sub_index >= it->second) {
                    ++it;
                    sub_index = 0;
                }

            }
        }
    }

}