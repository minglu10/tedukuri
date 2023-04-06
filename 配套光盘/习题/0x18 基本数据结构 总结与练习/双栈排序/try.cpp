#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool dfs(int i, int color, std::vector<int>& colors, const std::unordered_map<int64_t, std::unordered_set<int64_t>>& edges) {
    if (colors[i] != -1 && colors[i] != color) {
        return false;
    }
    if (colors[i] == color) return true;
    colors[i] = color;
    if (edges.count(i) > 0) {
        for (auto e : edges.at(i)) {
            if (!dfs(e, color^1, colors, edges)) {
                return false;
            }
        }
    }
    return true;
}

void Solve() {
    int n; 
    std::cin >> n;
    std::vector<int64_t> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    std::vector<int64_t> min_value_on_right(n + 1);
    min_value_on_right.back() = n + 1;
    std::unordered_map<int64_t, std::unordered_set<int64_t>> edges;
    for(int i = n - 1; i >=0; --i) {
        min_value_on_right[i] = std::min(min_value_on_right[i + 1], values[i]);
    }
    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (values[i] < values[j] && values[i] > min_value_on_right[j + 1]) {
                edges[i].insert(j);
                edges[j].insert(i);
            }
        }
    }
    std::vector<int> colors(n, -1);
    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            if (!dfs(i, 0, colors, edges)) {
                std::cout << 0 << std::endl;
                return;
            }
        }
    }
    std::stack<int64_t> stk1, stk2;
    int now = 1;
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
          	while (stk1.size() && stk1.top() == now)
			{
				stk1.pop();
				std::cout << "b ";
				now++;
			}
			stk1.push(values[i]);
			std::cout << "a ";
        } else {
           	while (true) {
				if (stk1.size() && stk1.top() == now)
				{
					stk1.pop();
					std::cout << "b ";
					now++;
				}
				else if (stk2.size() && stk2.top() == now)
				{
					stk2.pop();
					std::cout << "d ";
					now++;
				}
				else break;
            }
            stk2.push(values[i]);
            std::cout << "c ";
        }

    }
   	while (true) {
		if (stk1.size() && stk1.top() == now)
		{
			stk1.pop();
			std::cout << "b ";
			now++;
		}
		else if (stk2.size() && stk2.top() == now)
		{
			stk2.pop();
			std::cout << "d ";
			now++;
		}
		else break;
    }
	std::cout << std::endl ;
}

int main() {
    int p;
    std::cin >> p;
    for (int i = 0; i < p; ++i) {
        Solve();
    }
}