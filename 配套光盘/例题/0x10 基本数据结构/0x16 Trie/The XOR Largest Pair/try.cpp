#include <bits/stdc++.h>
#include <cstdint>
#include <unordered_map>
#include <vector>
std::string ConvertToBinary(uint32_t n) {
    std::string s = "";
    for(int i = 0; i < 32; ++i) {
        int k = (n >> i) & 1;
        if (k == 1) {
            s = '1' + s;
        } else {
            s = '0' + s;
        }
    }
    return s;

}
struct Node {
    std::unordered_map<char, Node> _children;
};

int main() {
    int n;
    std::cin >> n;
    Node root;
    std::vector<std::string> values;
    for (int i = 0; i < n; ++i) {
        uint32_t k;
        std::cin >> k;
        std::string s = ConvertToBinary(k);
        Node * cur = &root;
        for (int j = 0; j < s.size(); ++j) {
            char c = s[j];
            cur = &(cur->_children[c]);
        }
        values.push_back(std::move(s));
    }
    uint32_t ans = 0;
    for (int i = 0; i < n; ++i) {
        uint32_t temp = 0;
        const std::string& s = values[i];
        Node* cur = &root;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') {
                if (cur->_children.count('0')) {
                    temp |= (1 << (31 - j));
                    cur = &(cur->_children.at('0'));
                    continue;
                }
            } else if (s[j] == '0') {
                if (cur->_children.count('1')) {
                    temp |= (1 << (31 - j));
                    cur = &(cur->_children.at('1'));
                    continue;
                }
            }
            cur = &(cur->_children.at(s[j]));
        }
        ans = std::max(ans, temp);
        
    }
    std::cout << ans << std::endl;

}