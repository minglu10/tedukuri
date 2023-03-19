#include <bits/stdc++.h>
#include <cstdint>
#include <limits>
#include <queue>
#include <sstream>
#include <vector>
int main() {
    int64_t n, m, q, u, v, t;
    std::cin >> n >> m >> q >> u >> v >> t;
    std::vector<uint64_t> worms(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> worms[i];
    }
    std::sort(worms.begin(), worms.end());
    std::queue<int64_t> p1s;
    std::queue<int64_t> p2s;
    int64_t delta = 0;
    std::stringstream ss;
    for (int i = 1; i <= m; ++i) {
        int64_t maxx = std::numeric_limits<int64_t>::min();
        int k = 0;
        if (worms.size() > 0) {
            maxx = worms.back();
        }
        if (p1s.size() && p1s.front() > maxx) {
            maxx = p1s.front();
            k = 1;
        }
        if (p2s.size() && p2s.front() > maxx) {
            maxx = p2s.front();
            k = 2;
        }
        if (k == 0) worms.pop_back();
        else if (k == 1) p1s.pop();
        else p2s.pop();
        maxx += delta;
        int64_t p1 = maxx * u / v;
        int64_t p2 = maxx - p1;
        delta += q;
        p1s.push(p1 - delta);
        p2s.push(p2 - delta);
        if (i % t == 0) {
            ss << maxx << " ";
        }
    }
    std::string s = ss.str();
    s.pop_back();
    std::cout << s << std::endl;
    ss = std::stringstream();
    for (int i = 1; i <= m + n; ++i) {
        int64_t maxx = std::numeric_limits<int64_t>::min();
        int k = 0;
        if (worms.size() > 0) {
            maxx = worms.back();
        }
        if (p1s.size() && p1s.front() > maxx) {
            maxx = p1s.front();
            k = 1;
        }
        if (p2s.size() && p2s.front() > maxx) {
            maxx = p2s.front();
            k = 2;
        }
        if (k == 0) worms.pop_back();
        else if (k == 1) p1s.pop();
        else p2s.pop();
        maxx += delta;
        if (i % t == 0) ss << maxx << " ";
    }
    std::string s2 = ss.str();
    s2.pop_back();
    std::cout << s2 << std::endl;
}