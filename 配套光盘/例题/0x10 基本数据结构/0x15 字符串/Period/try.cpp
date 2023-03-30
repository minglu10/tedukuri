#include <bits/stdc++.h>

void Solve(const std::string& s, int case_n) {
   std::cout << "Test case #" << case_n << std::endl;
   std::vector<int> f(s.size(), 0);
   for (int i = 1; i < s.size(); ++i) {
     int k = f[i - 1];
     while(k > 0) {
         if (s[k] == s[i]) {
             f[i] = k + 1;
             break;
         }
         k = f[k - 1];
     }
     
     if (f[i] == 0)  {
        f[i] = s[i] == s[0];
     }
     int n_char = i + 1;
     if (n_char % (n_char - f[i]) == 0) {
        int k = n_char / (n_char - f[i]);
        if (k > 1) {
            std::cout << (i + 1) << " " << k << std::endl;
        }
     }
   } 
   std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    int case_n = 1;
    while(n > 0) {
        std::string s;
        std::cin >> s;
        Solve(s, case_n);
        std::cin >> n;
        ++case_n;
    }
    return 0;
}