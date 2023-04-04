#include <bits/stdc++.h>
#include <utility>
int main() {
    int64_t i = 0;
    char c;
    std::vector<std::pair<char, int64_t>> stack;
    stack.push_back(std::make_pair('A', -1));
    int64_t ans = 0;

    while(std::cin >> c) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(std::make_pair(c, i));
        } else {
            if((c == ')' && stack.back().first == '(')
            ||(c == ']' && stack.back().first == '[') 
            ||(c == '}' && stack.back().first == '{')
             ) {
                stack.pop_back();
                ans = std::max(ans, i - stack.back().second);

            } else {
                stack.push_back(std::make_pair(c, i));
            }
        }
        ++i;
    }
    std::cout << ans << std::endl;
}