#include <bits/stdc++.h>
#include <limits>
#include <unordered_map>
struct ValPos{
    int val;
    int pos;
    bool operator < (const ValPos& v1) {
        if (val != v1.val) {
            return val < v1.val;
        }
        return pos < v1.pos;
    }
};
int main() {
    int n;
    std::cin >> n;
    std::vector<ValPos> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i].val;
        values[i].pos = i;
    }
    std::sort(values.begin(), values.end());
    std::unordered_map<int, std::vector<int>> blocks;
    int cont = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || values[i].val != values[i - 1].val) {
            ++cont;
        }
        blocks[cont].push_back(values[i].pos);
    }
    int ans = 1;
    bool flag = 0;
    int last = std::numeric_limits<int>::max();
    for (int i = 0; i < cont; ++i) {
        int siz = blocks[i].size();
        if (flag) {
            if (last < blocks[i][0]) last = blocks[i][siz - 1];
            else {
                flag ^= 1;
                ans++;
                last = blocks[i][0];
            }


        } else {
            if (last > blocks[i][siz -1]) last = blocks[i][0];
            else {
                flag ^= 1;
                last = blocks[i][siz - 1];
            }
        }
    }
    std::cout << ans << std::endl;
}