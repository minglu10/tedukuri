#include <boost/unordered/unordered_flat_map.hpp>
#include <bits/stdc++.h>
#include <deque>

int main() {
    int Q;
    std::cin >> Q;
    boost::unordered::unordered_flat_map<int, int> max_value;
    std::vector<int> values_before_cursor;
    std::vector<int> cum_sums;
    std::deque<int> values_after_cursor;
    for (int i = 0; i < Q; ++i) {
        char c;
        int val;
        std::cin >> c;
        switch(c) {
            case 'I':  {
                std::cin >> val;
                values_before_cursor.push_back(val);
                int sum = val;
                if (cum_sums.size())
                    sum = cum_sums.back() + val;
                cum_sums.push_back(sum);
                int k = values_before_cursor.size();
                int cur_max = sum;
                if (max_value.count(k - 1))
                    cur_max = std::max(max_value[k - 1], cur_max);
                max_value[k] = cur_max;
            }
            break;
            case 'D': {
                if (values_before_cursor.size()) {
                    values_before_cursor.pop_back();
                    cum_sums.pop_back();
                }
                break;
            }
            case 'L': {
                if (values_before_cursor.size()) {
                    int val = values_before_cursor.back();
                    values_before_cursor.pop_back();
                    cum_sums.pop_back();
                    values_after_cursor.push_front(val);
                }
                break;
            }
            case 'R': {
                if (!values_after_cursor.empty()) {
                    int val = values_after_cursor.front();
                    values_after_cursor.pop_front();
                    values_before_cursor.push_back(val);
                    int sum =  val;
                    if (cum_sums.size()) 
                        sum += cum_sums.back();
                    cum_sums.push_back(sum);
                    int k = values_before_cursor.size();
                    int cur_max = sum;
                    if (max_value.count(k - 1))
                        cur_max = std::max(max_value[k - 1], sum);
                    max_value[k] = cur_max;
                }
                break;
                
            }
            case 'Q': {
                int  k;
                std::cin >> k;
                std::cout << max_value[k] << std::endl;
            }
            break;
        }
    }

}