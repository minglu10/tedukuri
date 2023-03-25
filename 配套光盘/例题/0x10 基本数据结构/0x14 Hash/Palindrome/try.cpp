#include <bits/stdc++.h>
#include <cstddef>
#include <cstdint>
#include <vector>

constexpr uint64_t prime = 131;
int getMaxPalindrome(const std::string&s, const std::vector<uint64_t>& hash_forward, const std::vector<uint64_t>& hash_backward, const std::vector<uint64_t>& power, int i, int j) {
    int left = 0, right = std::min(i + 1, (int)s.size() - j);
    while(left < right) {
        int mid = (left + right  + 1) / 2;
        int left_idx = i + 1 - mid;
        uint64_t left_hash = hash_backward[left_idx] - hash_backward[i + 1] * power[mid]; 
        int right_idx = j + mid - 1;
        uint64_t right_hash = hash_forward[right_idx] - hash_forward[j - 1] * power[mid];
        if (left_hash == right_hash) {
            left = mid;
        } else {
            right = mid - 1;
        }

    }
    return left;

}
void Solve(const std::string& s, int case_number) {
    std::vector<uint64_t> hash_forward(s.size() , 0);
    std::vector<uint64_t> hash_backward(s.size(), 0);
    std::vector<uint64_t> power(s.size() + 1, 1);
    uint64_t accum = 0;
    for (int i = 1; i < power.size(); ++i) {
        power[i] = power[i - 1] * prime;
    }
    for (int i = 0; i < s.size(); ++i) {
        accum = accum * prime + s[i] - 'a' + 1;
        hash_forward[i] = accum;
    }
    accum = 0;
    for (int i = s.size() - 1; i >=0; --i ) {
        accum = accum * prime + s[i] - 'a' + 1;
        hash_backward[i] = accum;
    }
    int ans = 1;
    for (int i = 0; i < s.size() - 1; ++i) {
        int k = getMaxPalindrome(s, hash_forward, hash_backward, power, i, i + 1);
        ans = std::max(ans, 2 * k);
    }
    for (int i = 1; i < s.size() - 1; ++i) {
        int k = getMaxPalindrome(s, hash_forward, hash_backward, power, i - 1, i + 1);
        ans = std::max(ans, 2 * k + 1);
    }
    std::cout << "Case " << case_number << ": " << ans << std::endl;


}

int main() {
    int case_number = 1;
    while(true) {
        std::string s;
        std::cin >> s;
        if (s == "END") {
            break;
        }
        Solve(s, case_number);
        ++case_number;

    }

}