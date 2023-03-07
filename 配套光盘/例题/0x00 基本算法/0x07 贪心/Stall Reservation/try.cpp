#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#include <boost/unordered/unordered_flat_map.hpp>
#include <boost/unordered/unordered_flat_set.hpp>
struct Cow {
    int start = 0;
    int end = 0;
    int index = 0;
    bool operator < (const Cow& c2) {
        if (start != c2.start) {
            return start < c2.start;
        }
        if (end != c2.end) {
            return end < c2.end;
        }
        return index < c2.index;
    }

};
int main() {
    int  N;
    std::cin >> N;
    std::vector<Cow> cows(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> cows[i].start;
        std::cin >> cows[i].end;
        cows[i].index = i;
    }
    std::sort(cows.begin(), cows.end());
    auto comp = [](const std::pair<int, int>&p1, const std::pair<int,int>&p2) ->bool {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        } else {
            return p1.second > p2.second;
        }
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)>  stall_queue(comp);
    std::unordered_map<int, int>  id_stall;
    int cur_stall_number = 0;
    for (int i = 0; i < cows.size(); ++i) {
        if (stall_queue.empty() || stall_queue.top().first >= cows[i].start) {
            ++cur_stall_number;
            id_stall[cows[i].index] = cur_stall_number;
            stall_queue.push(std::make_pair(cows[i].end, cur_stall_number));
        } else {
            id_stall[cows[i].index] = stall_queue.top().second;
            stall_queue.pop();
            stall_queue.push(std::make_pair(cows[i].end, id_stall[cows[i].index]));
        }
    }
    std::cout << cur_stall_number << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << id_stall[i] << std::endl;
    }
    return 0;
    
}