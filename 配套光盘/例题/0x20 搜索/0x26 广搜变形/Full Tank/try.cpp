#include <bits/stdc++.h>
#include <cstddef>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
std::vector<int> gas_cities;
std::unordered_map<int, std::vector<std::pair<int, int>>> roads;
void Solve(int gas_cap, int start_city, int end_city) {
    std::priority_queue<std::pair<int, std::pair<int, int>>> queue;
    queue.push(std::make_pair(0, std::make_pair(start_city, 0)));
    auto hash = [](const std::pair<int, int>& v)->size_t {
        return (std::hash<int>()(v.first) * 1331) ^ std::hash<int>()(v.second);
    };
    std::unordered_map<std::pair<int, int>, int, decltype(hash) > dist(10, hash);
    dist[std::make_pair(start_city, 0)] = 0;
    std::unordered_set<std::pair<int, int>, decltype(hash)> spaned(10, hash);
    while(queue.size() > 0) {
        const auto& top_queue = queue.top();
        auto cur_city = top_queue.second.first;
        auto cur_gas = top_queue.second.second;
        auto cur_cost = -top_queue.first;
        queue.pop();
        if (cur_city == end_city) {
            std::cout << cur_cost << std::endl;
            return;
        }
        if (spaned.count(std::make_pair(cur_city, cur_gas)) > 0) continue;
        spaned.insert(std::make_pair(cur_city, cur_gas));
        if (cur_gas < gas_cap) {
            auto new_cost = cur_cost + gas_cities[cur_city];
            auto new_state = std::make_pair(cur_city, cur_gas + 1);
            if (dist.count(new_state) == 0 || 
                dist[new_state] > new_cost) {
                dist[new_state] = new_cost;
                queue.push(std::make_pair(-new_cost, new_state));
            }
        }
        if (roads.count(cur_city) == 0) {
            continue;;
        }
        for(const auto edge : roads[cur_city]) {
            auto new_city = edge.first;
            auto d = edge.second;
            if (cur_gas < d) continue;
            auto new_state = std::make_pair(new_city, cur_gas - d);
            if (dist.count(new_state) == 0 ||
                dist[new_state] > cur_cost
            ) {
                queue.push(std::make_pair(-cur_cost, new_state));
                dist[new_state] = cur_cost;
            }
        }
    }
    std::cout << "impossible" << std::endl;
}


int main() {
    int n, m;
    std::cin >> n >> m;
    gas_cities.resize(n);
    for (int i = 0; i < gas_cities.size(); ++i) {
        std::cin >> gas_cities[i];
    }
    for (int i = 0; i < m; ++i) {
        int s, d, l;
        std::cin >> s >> d >> l;
        roads[s].push_back(std::make_pair(d, l));
        roads[d].push_back(std::make_pair(s, l));
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
	    int c, st, ed;
        std::cin >> c >> st >> ed;
        Solve(c, st, ed);
    }


}