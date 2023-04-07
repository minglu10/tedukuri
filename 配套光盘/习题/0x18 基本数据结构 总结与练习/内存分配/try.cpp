#include <bits/stdc++.h>
#include <queue>
#include <utility>

struct Job {
    int64_t _start_time = 0;
    int64_t _memory_usage = 0;
    int64_t _running_time = 0;
};
std::map<int64_t, int64_t> current_running; //start, end memory of running tasks
std::priority_queue<std::pair<int64_t, int64_t>> job_finish_queue; // finish time, starting memory
std::queue<Job> waiting_list; //waiting jobs with starting time, number of memory and running time
int64_t max_time_finish = 0;


bool InsertNewJob(const Job& job) {
    for (auto it = current_running.cbegin(); it != current_running.cend(); ++it) {
        auto it2 = it;
        ++it2;
        if (it2 == current_running.cend()) return false;
        if (it2->first - it->second - 1 >= job._memory_usage) {
            current_running.insert(std::make_pair(it->second + 1, it->second + job._memory_usage));
            job_finish_queue.push(std::make_pair(-(job._start_time + job._running_time), it->second + 1));
            max_time_finish = std::max(max_time_finish, job._start_time + job._running_time );
            return true;
        }
    }
    return false;
}

void HandelTime(int64_t T) {
    while(job_finish_queue.size() && job_finish_queue.top().first >= (-T)) {
        int64_t t1 = -job_finish_queue.top().first;
        while(job_finish_queue.size() && job_finish_queue.top().first == -t1) {
            int64_t start_memory = job_finish_queue.top().second;
            job_finish_queue.pop();
            current_running.erase(start_memory);
        }
        while(waiting_list.size() && waiting_list.front()._start_time <= t1) {
            Job j1 = waiting_list.front();
            j1._start_time = t1;
            if(InsertNewJob(j1)) {
                waiting_list.pop();
            } else{
                break;
            }
        }
    }
}

int main() {
    int64_t n = 0;
    std::cin >> n;
    current_running.insert(std::make_pair(-1, -1));
    current_running.insert(std::make_pair(n, n));
    
    int64_t T, M, P;
    int64_t wait_ing = 0;
    while(true) {
        std::cin >> T >> M >> P;
        if (T == 0 && M == 0 && P == 0) {
            break;
        }
        HandelTime(T);
        Job job {T, M, P};
        if (!InsertNewJob(job)) {
            waiting_list.push(job);
            ++wait_ing;
        }
        int64_t kkk = 10;
    }
    HandelTime(1000000000);
    std::cout << max_time_finish << std::endl;
    std::cout << wait_ing << std::endl;
    


}