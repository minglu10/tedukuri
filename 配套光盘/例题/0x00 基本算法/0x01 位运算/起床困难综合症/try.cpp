//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string>

uint32_t getValue(const std::vector<std::pair<std::string, uint32_t>>& gates, uint32_t init_value, int bit_pos) {
    for (int i = 0; i < gates.size(); ++i) {
        int op_value = (gates[i].second >> bit_pos) & 1;
        if (gates[i].first == "AND") {
            init_value &= op_value;
        } else if (gates[i].first == "OR") {
            init_value |= op_value;
        } else {
            init_value ^= op_value;
        }
    }
    return init_value;
}
uint32_t getMaxHurt(const std::vector<std::pair<std::string, uint32_t>>& gates, int limit) {
    int cur_val = 0;
    uint32_t ans = 0;
    for (int bit_pos = 30; bit_pos >= 0; --bit_pos) {
        int v0 = getValue(gates, 0, bit_pos);
        if ((v0 == 1) ||((cur_val + (1 << bit_pos)) > limit)) {
            ans += (v0 << bit_pos);
            continue;
        }
        int v1 = getValue(gates, 1, bit_pos);
        if (v1 > v0) {
            cur_val += (1 << bit_pos);
            ans += (v1 << bit_pos);
        } else {
            ans += (v0 << bit_pos);
        }
    }
    return ans;

}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<std::string, uint32_t>> gates;
    gates.resize(n);
    for (int i = 0; i < n; ++i) {
        char op[5];
        int k;
        scanf("%s %d", op, &k);
        gates[i].first = op;
        gates[i].second = k;
    }
    std::cout << getMaxHurt(gates, m) << std::endl;
}