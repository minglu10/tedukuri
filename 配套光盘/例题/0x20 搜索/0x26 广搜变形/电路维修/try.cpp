#include <bits/stdc++.h>
#include <deque>
#include <utility>
#include <vector>
int n, m;
std::vector<std::string> values;
std::vector<std::vector<int>> dist;
std::deque<std::pair<int, int>> queue;

bool valid(int x, int y) {
    return (x >=0 && x <=n && y >=0 && y <= m);
}
void addQueue(int x, int y, int new_dist) {
    if (dist[x][y] == -1 || dist[x][y] > new_dist) {
        dist[x][y] = new_dist;
        if (queue.size() == 0) {
            queue.push_back(std::make_pair(x, y));
        } else {
            auto d1 = dist[queue.front().first][queue.front().second];
            if (d1 > new_dist) {
                queue.push_front(std::make_pair(x, y));
            } else {
                queue.push_back(std::make_pair(x, y));
            }
        }
    }
}

void Solve() {
    std::cin >> n >> m;
    values.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    dist.resize(n + 1);
    for (int i = 0; i < dist.size(); ++i) {
        std::vector<int> x(m + 1, -1);
        std::swap(dist[i], x);
    }
    queue.clear();
    dist[0][0] = 0;
    queue.push_back(std::make_pair(0, 0));
    while(queue.size()) {
        auto p = queue.front();
        int x = p.first;
        int y = p.second;
        queue.pop_front();
        if (valid(x - 1, y - 1)) {
            if (values[x -1][y-1] == '\\') {
                addQueue(x - 1, y - 1, dist[x][y]);
            } else {
                addQueue(x - 1, y - 1, dist[x][y] + 1);
            }
        } 
        if (valid(x - 1, y +1)) {
            if (values[x - 1][y] == '\\') {
                addQueue(x - 1, y + 1, dist[x][y] + 1);
            } else {
                addQueue(x - 1, y + 1, dist[x][y]);
            }
        }
        if (valid(x + 1, y -1)) {
            if (values[x][y - 1] == '\\') {
                addQueue(x + 1, y - 1, dist[x][y] + 1);
            } else {
                addQueue(x + 1, y - 1, dist[x][y]);
            }
        }
        if (valid(x + 1,  y + 1)) {
            if (values[x][y] == '\\') {
                addQueue(x + 1, y + 1, dist[x][y]);
            } else {
                addQueue(x + 1, y + 1, dist[x][y] + 1);
            }

        }
    }
    if (dist[n][m] == -1) {
        std::cout << "NO SOLUTION" << std::endl;
    } else {
        std::cout << dist[n][m] << std::endl;
        
    }


}
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        Solve();
}