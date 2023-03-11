#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
std::unordered_map<int, std::vector<std::string>> buffers;
const std::vector<std::string>& getString(int i) {
    if (buffers.count(i)) {
        return buffers.at(i);
    }
    if (i == 1) {
        std::string s{"X"};
        std::vector<std::string> ans;
        ans.push_back(s);
        buffers[1] = std::move(ans);
        return buffers[1];
    }
    auto ans_pre = getString(i - 1);
    std::vector<std::string> ans;
    for (int i = 0; i < ans_pre.size(); ++i) {
        std::string s1 = ans_pre[i]; 
        std::string s2(ans_pre[i].size(), ' ');
        ans.push_back(s1 + s2 + s1);
    }
    for (int i = 0; i < ans_pre.size(); ++i) {
        std::string s1 = ans_pre[i]; 
        std::string s2(ans_pre[i].size(), ' ');
        ans.push_back(s2 + s1 + s2);
    } 
    for (int i = 0; i < ans_pre.size(); ++i) {
        std::string s1 = ans_pre[i]; 
        std::string s2(ans_pre[i].size(), ' ');
        ans.push_back(s1 + s2 + s1);
    } 
    buffers[i] = std::move(ans);
    return buffers[i];

}    
int main() {
    while(true) {
        int i;
        std::cin >> i;
        if (i == -1) break;
        auto ans = getString(i);
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << std::endl;
        }
        std::cout << "-" << std::endl;

    }
}