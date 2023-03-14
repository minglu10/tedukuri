#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>

struct XY {
    int x;
    int y;
};

std::vector<XY> clover_fields;
std::set<int> original_xs;
std::set<int> original_ys;
std::map<int, int> original_to_new_xs;
std::map<int, int> original_to_new_ys;
std::map<int, int> new_to_original_xs;
std::map<int, int> new_to_original_ys;
std::vector<std::vector<int>> sum_new_xys;

bool isValid(int len, int C) {
    int origin_x_start = len - 1;
    int origin_y_start = len - 1;
    auto itx = original_to_new_xs.lower_bound(origin_x_start);
    if (itx->first > origin_x_start) --itx;
    auto ity = original_to_new_ys.lower_bound(origin_y_start);
    if (ity->first > origin_y_start) --ity;
    for (int i = itx->second; i < new_to_original_xs.size(); ++i) {
        int origin_x_end = new_to_original_xs[i];
        int origin_x_start = origin_x_end + 1 - len;
        auto itxx = original_to_new_xs.lower_bound(origin_x_start);
        int new_x_start = itxx->second;
        for (int j = ity->second; j < new_to_original_ys.size(); ++j) {
            int origin_y_end = new_to_original_ys[j];
            int origin_y_start = origin_y_end + 1 - len;
            auto ityy = original_to_new_ys.lower_bound(origin_y_start);
            int new_y_start = ityy->second;
            auto sum = sum_new_xys[i][j];
            if (new_x_start > 1) {
                sum -= sum_new_xys[new_x_start - 1][j];
            }
            if (new_y_start > 1) {
                sum -= sum_new_xys[i][new_y_start - 1];
            }
            if (new_x_start > 1 && new_y_start > 1) {
                sum += sum_new_xys[new_x_start - 1][new_y_start - 1];
            }
            if (sum >= C) return true;
        }
    }
    return false;
}

int main() {
    int C, N;
    std::cin >> C >> N;
    clover_fields.resize(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> clover_fields[i].x >> clover_fields[i].y;
    }
    for(const auto& xy : clover_fields) {
        original_xs.insert((xy.x));
        original_ys.insert((xy.y));
    }
    original_xs.insert(0);
    original_xs.insert(10002);
    original_ys.insert(0);
    original_ys.insert(10002);
    int ix = 0; 
    for (const auto & x : original_xs) {
        original_to_new_xs[x] = ix;
        new_to_original_xs[ix] = x;
        ++ix;
    }
    int iy = 0; 
    for (const auto & y : original_ys) {
        original_to_new_ys[y] = iy;
        new_to_original_ys[iy] = y;
        ++iy;
    }
    sum_new_xys = std::vector<std::vector<int>>(new_to_original_xs.size(), std::vector<int>(new_to_original_ys.size(), 0));
    for(const auto& xy : clover_fields) {
        int new_x = original_to_new_xs.at(xy.x);
        int new_y = original_to_new_ys.at(xy.y);
        sum_new_xys[new_x][new_y] += 1;
    }
    for (int i = 0; i < sum_new_xys.size(); ++i) {
        for (int j = 0; j < sum_new_xys[0].size(); ++j) {
            if (i > 0) {
                sum_new_xys[i][j] += sum_new_xys[i - 1][j]; 
            }
            if (j > 0) {
                sum_new_xys[i][j] += sum_new_xys[i][j - 1]; 
            }
            if (i > 0 && j > 0) {
                sum_new_xys[i][j] -= sum_new_xys[i - 1][j - 1]; 
            }
        }
    }
    int right = 10002;
    int left = 1;
    while(left < right) {
        int mid = (left + right) / 2;
        if (isValid(mid,  C)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    } 
    std::cout << left << std::endl;


}