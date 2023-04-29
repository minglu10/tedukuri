#include <bits/stdc++.h>
#include <sstream>
#include <unordered_map>
#include <vector>
int n = 0;
int dfs(std::vector<int>& values, int depth) {
    if (values.size() == depth) {
        return values.back() == n;
    }
    int size = values.size();
    std::unordered_set<int> tried;
    for (int j = size - 1; j >= 0; --j) {
        for (int k = j; k >= 0; --k) {
            int v = values[j] + values[k];
            if (v > n) continue;
            if (v <= values.back()) continue;
            if (tried.count(v)) continue;
            values.push_back(v);
            if (dfs(values, depth)) {
                return true;
            }
            tried.insert(v);
            values.pop_back();
        }
    }
    return false;

}

int main() {
    while(true) {
        std::cin >> n;
        if(n == 0) {
            break;
        }
        std::vector<int> values{1};
        for(int i = 1; i <=n; ++i) {
            if(dfs(values, i)) {
                std::stringstream ss;
                ss << values.size() << "   ";
                for (auto v : values) {
                    ss << v << " ";
                }
                std::string s = ss.str();
                s.pop_back();
                std::cout << s << std::endl;
                break;
            }
        }
    }
}