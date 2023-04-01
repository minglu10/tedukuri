#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
struct Tire {
    std::unordered_map<char, Tire> _children;

};
std::string ConvertInt(int value) {
    std::string s = ""; 
    for (int i = 31;  i >=0; --i) {
        if (1 & (value >> i)) {
            s += '1';
        } else {
            s += '0';
        }
    }
    return s;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int>  D(n, -1);
    D[0] = 0;
    std::vector<int> child_to_father(n, 0);
    std::vector<int> child_to_cost(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int m, n, k;
        std::cin >> m >> n >> k;
        child_to_father[n] =  m;
        child_to_cost[n] = k;
    }
    for (int i = 1;  i < n; ++i) {
        std::vector<int> stack;
        int k = i;
        while(D[k] == -1) {
            stack.push_back(k);
            k = child_to_father[k];
        }
        int xor_value = D[k];
        for (int j = stack.size() - 1; j >= 0; --j) {
            xor_value ^= child_to_cost[stack[j]];
            D[stack[j]] = xor_value;
        }
    }
    Tire root;
    for (int i = 0; i < n; ++i) {
        const std::string s = ConvertInt(D[i]); 
        Tire* p_node = &root;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            p_node = &((p_node->_children)[c]);
        }
    } 
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int ans_i = 0;
        std::string s = ConvertInt(D[i]);
        Tire* p_node = &root;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (p_node->_children.count('1') > 0) {
                    ans_i |= (1 << (31 - i));
                    p_node = &(p_node->_children['1']);
                    continue;
                }
            }
            if (s[i] == '1') {
                if (p_node->_children.count('0') > 0) {
                    ans_i |= (1 << (31 - i));
                    p_node = &(p_node->_children['0']);
                    continue;;
                }
            }
            p_node = &(p_node->_children[s[i]]);
        }
        ans = std::max(ans, ans_i);
    }
    std::cout << ans << std::endl;

}