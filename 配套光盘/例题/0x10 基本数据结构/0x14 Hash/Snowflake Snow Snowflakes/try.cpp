#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <unordered_map>
struct Snow{
    uint32_t length[6];
};
size_t GetHash(const Snow& snow) {
    constexpr uint32_t prime = 100002797;
    size_t sum= 0; size_t mul = 1; 
    for (int i = 0; i < 6; ++i) {
        sum += (snow.length[i] % prime);
        sum %= prime;
        mul *= (snow.length[i] % prime);
        mul %= prime;
    }
    return ((sum << 32) + mul) % prime;
}

bool Match(const Snow& s1, const Snow&s2) {
    for (int i = 0; i < 6; ++i) {
        bool match = true;
        for (int j = 0; j < 6; ++j) {
            if (s1.length[j] != s2.length[(i + j) % 6]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    for (int i = 0; i < 6; ++i) {
        bool match = true;
        for (int j = 0; j < 6; ++j) {
            if (s1.length[j] != s2.length[(6 + i - j) % 6]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;

}

int main() {
    int n;
    std::cin >> n;
    std::vector<Snow> values(n);
    std::unordered_map<uint64_t, std::vector<int>> hashed;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cin >> values[i].length[j];
        }
        hashed[GetHash(values[i])].push_back(i);
    }
    for (const auto& hash : hashed) {
        if (hash.second.size() < 2) {
            continue;
        }
        for (int i = 0; i < hash.second.size(); ++i) {
            for (int j = i + 1; j < hash.second.size(); ++j) {
                if (Match(values[hash.second[i]], values[hash.second[j]])) {
                    std::cout << "Twin snowflakes found." << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No two snowflakes are alike." << std::endl;
    return 0;

}