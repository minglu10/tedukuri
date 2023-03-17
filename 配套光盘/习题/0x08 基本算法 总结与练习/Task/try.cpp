#include <bits/stdc++.h>
#include <bits/types/time_t.h>
struct XY{
    int64_t time;
    int64_t complexity;
};
int main() {
    int n_machines, n_tasks;
    std::cin >> n_machines >> n_tasks;
    std::vector<XY> machines(n_machines);
    for (int i = 0; i < n_machines; ++i) {
        std::cin >> machines[i].time >> machines[i].complexity;
    }
    std::vector<XY> tasks(n_tasks);
    for (int i = 0; i < n_tasks; ++i) {
        std::cin >> tasks[i].time >> tasks[i].complexity;
    }
    std::sort(tasks.begin(), tasks.end(), [](const XY& p1, const XY& p2) {
        if(p1.time == p2.time) return p1.complexity > p2.complexity;
        return p1.time > p2.time;
    });
    std::sort(machines.begin(), machines.end(), [](const XY& p1, const XY& p2) {
        if(p1.time == p2.time) return p1.complexity > p2.complexity;
        return p1.time > p2.time;
    });
    std::map<int64_t, int64_t> machine_complex_map;
    int j = 0;
    int n_ans = 0;
    int64_t rewards = 0;
    for (int i = 0; i < tasks.size(); ++i) {
        const XY& cur_task = tasks[i];
        while(j < n_machines && machines[j].time >= cur_task.time) {
            machine_complex_map[machines[j].complexity] += 1;
            ++j;
        }
        auto it = machine_complex_map.lower_bound(cur_task.complexity);
        if (it != machine_complex_map.end()) {
            ++n_ans;
            rewards += cur_task.time * 500 + 2 * cur_task.complexity;
            --it->second;
            if (it->second == 0) {
                machine_complex_map.erase(it);
            }
        }
    }
    std::cout << n_ans << " " << rewards << std::endl;

}