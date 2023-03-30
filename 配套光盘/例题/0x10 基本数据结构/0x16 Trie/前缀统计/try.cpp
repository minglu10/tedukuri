#include <bits/stdc++.h>
#include <cstdint>
#include <unordered_map>
struct Node {
    uint64_t _n_node = 0;
    std::unordered_map<char, Node> _children;
};
int main() {
    int N, M;
    std::cin >> N >> M;
    Node root;
    for (int i = 0; i < N; ++i) {
        std::string s;
        std::cin >> s;
        Node* cur = &root;
        for (int j = 0; j < s.size() - 1; ++j) {
            int c = s[j];
            cur = &(((*cur)._children)[c]);
        }
        int c = s.back();
        cur = &(((*cur)._children)[c]);
        cur->_n_node += 1;
    }
    for (int i = 0; i < M; ++i) {
        std::string s;
        std::cin >> s;
        Node *cur = &root;
        uint64_t ans = 0;
        for (int j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (cur->_children.count(c) == 0) {
                break;
            }
            cur = &(cur->_children.at(c));
            ans += cur->_n_node;
        }
        std::cout << ans << std::endl; 
    }
}