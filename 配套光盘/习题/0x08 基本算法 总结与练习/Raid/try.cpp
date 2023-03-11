#include <bits/stdc++.h>
#include <cmath>
#include <limits>
#include <vector>
struct Point {
    double x;
    double y;
    bool is_station;
    bool operator < (const Point& p) {
        return x < p.x;
    }
};

double getDistance(const Point& p1, const Point& p2) {
    if (p1.is_station == p2.is_station) {
        return std::numeric_limits<double>::infinity();
    }
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double getMinDist(const std::vector<Point>& points, int left, int right) {
    if (left + 1 >= right) return getDistance(points[left], points[right]);
    int mid = (left + right) / 2;
    double d = std::min(getMinDist(points, left, mid), getMinDist(points, mid + 1, right));
    for(int i = mid; i >= left; --i) {
        if ((points[mid].x - points[i].x) > d) break;
        for(int j = mid + 1; j <= right; ++j) {
            if ((points[j].x - points[i].x) > d) break;
            d = std::min(d, getDistance(points[i], points[j]));
        }

    }
    return d;
}

void Solve() {
    int N;
    std::cin >> N;
    std::vector<Point> points;
    points.reserve(2 * N);
    for (int i = 0; i < N; ++i) {
        Point p;
        std::cin >> p.x >> p.y;
        p.is_station = true;
        points.push_back(std::move(p));
    }
    for (int i = 0; i < N; ++i) {
        Point p;
        std::cin >> p.x >> p.y;
        p.is_station = false;
        points.push_back(std::move(p));
    }
    std::sort(points.begin(), points.end());
    double d = getMinDist(points, 0, points.size() - 1);
    printf("%.3f\n", d);

}
int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        Solve();
    }
}