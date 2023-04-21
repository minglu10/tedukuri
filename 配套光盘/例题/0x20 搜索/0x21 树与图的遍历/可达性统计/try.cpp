#include "boost/dynamic_bitset/dynamic_bitset.hpp"
#include <bits/stdc++.h>
#include <bitset>
#include <unordered_map>
#include <valarray>
#include <boost/dynamic_bitset.hpp>
int FindConnections(const std::unordered_map<int, std::unordered_set<int>>& parent_children,
    const std::unordered_map<int, int>& child_parent,
    std::unordered_map<int, int>& n_connections, int k, std::vector<boost::dynamic_bitset<>>& bitsets) {
        if (n_connections.count(k) > 0) {
            return n_connections.at(k);
        }
        int ans;
        if (parent_children.count(k) == 0) {
            ans = 1;
        } else {
            for (auto i : parent_children.at(k)) {
                 FindConnections(parent_children, child_parent, n_connections, i, bitsets);
                 bitsets[k] |= bitsets[i];
            }
            ans = 0;
            for(int i = 1; i <bitsets[k].size(); ++i) {
                ans += bitsets[k].test(i);
            }
        }
        n_connections[k] = ans;
        return ans;
}
int main() {
    int m, n;
    std::cin >> m >> n;
    std::unordered_map<int, std::unordered_set<int>> parent_children;
    std::unordered_map<int, int> child_parent; 
    for (int i = 0; i < n; ++i) {
        int p, c;
        std::cin >> p >> c;
        parent_children[p].insert(c);
        child_parent[c] = p;
    }
    std::vector<boost::dynamic_bitset<>> bitsets;
    for (int i = 0; i <= m; ++i) {
        boost::dynamic_bitset<> x(m +1);
        x[i] = 1;
        bitsets.push_back(std::move(x));
    }
    std::unordered_map<int, int> n_connections;
    for (int i = 1; i <= m; ++i) {
        std::cout << FindConnections(parent_children, child_parent, n_connections, i, bitsets) << std::endl;
    }

}