#include <bits/stdc++.h>
#include <unordered_map>
struct Trie {
    int _ends = 0;
    std::unordered_map<int, Trie> _children;
};
void Solve() {
    int n;
    std::cin >> n;
    Trie root;
    std::vector<std::string> values;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        Trie * cur =&root;
        for (int j = 0; j < s.size(); ++j) {
            int c = s[j] - '0';
            if (cur->_children.count(c) == 0) {
                cur->_children[c] = Trie();
            }
            cur = &cur->_children[c];
        }
        cur->_ends += 1;
        values.push_back(s);
    }
    for (int i = 0; i < values.size(); ++i) {
        const std::string& s = values[i];
        Trie *cur = &root;
        for (int j = 0; j < s.size(); ++j) {
            int c = s[j] - '0';
            cur = &cur->_children.at(c);
            if (cur->_ends) {
                if (cur->_children.size() > 0) {
                    std::cout << "NO" << std::endl;
                    return;
                }
            }
        }
        
    }
    std::cout << "YES" << std::endl;

}
int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        Solve();
    }

}