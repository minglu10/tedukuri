#include<iostream>
#include <vector>

void calc(int cur, int n, int m, std::vector<int>& cur_values) {
    if (cur_values.size() == m) {
        for (int c : cur_values) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        return;
    }
    if ((cur_values.size() + (n - cur + 1)) < m) return;
    calc(cur + 1, n, m, cur_values);
    cur_values.push_back(cur);
    calc(cur + 1, n, m, cur_values);
    cur_values.pop_back();

}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> cur;
    calc(1, n, m, cur);
}
