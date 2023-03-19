#include <bits/stdc++.h>
#include <cstddef>
#include <queue>
#include <string>
#include <unistd.h>
#include <unordered_map>

void Solve(int case_number, int n_team) {
    std::cout << "Scenario #" << case_number << std::endl;
    std::unordered_map<int, int> mem_to_team;
    int team_number = 0;
    for (int i = 0; i < n_team; ++i) {
        int n_member;
        std::cin >> n_member;
        for(int j = 0; j < n_member; ++j) {
            int k;
            std::cin >> k;
            mem_to_team[k] = team_number;
        }
        ++team_number;
    }
    std::queue<int> big_queue;
    std::unordered_map<int, std::queue<int>> small_queues;
    while(true) {
        std::string s;
        std::cin >> s;
        if (s == "STOP") {
            break;
        }
        if (s == "ENQUEUE") {
            int member;
            std::cin >> member;
            int team_number = mem_to_team.at(member);
            if (small_queues.count(team_number) == 0) {
                big_queue.push(team_number);
            }
            small_queues[team_number].push(member);
        } else {
            int team_number = big_queue.front();
            std::cout << small_queues.at(team_number).front() << std::endl;
            small_queues.at(team_number).pop();
            if (small_queues.at(team_number).empty()) {
                big_queue.pop();
                small_queues.erase(team_number);
            }
        }
        
    }
    std::cout << std::endl;


}

int main() {
    int n;
    int case_n = 1;
    while(true) {
        std::cin >> n;
        if (n == 0) break;
        Solve(case_n++, n);
    }

}