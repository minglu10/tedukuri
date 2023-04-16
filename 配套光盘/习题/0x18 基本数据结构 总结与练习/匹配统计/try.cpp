#include <bits/stdc++.h>
#include <cstdint>
#include <unordered_map>
#include <vector>
constexpr uint64_t prime = 1331;
int calcMatch (int i, const std::vector<uint64_t>&hash_a, const std::vector<uint64_t>& hash_b, const std::vector<uint64_t>& powers) {
    int left = i;
    int right = std::min(hash_a.size() - 1, i + hash_b.size() - 1);
    uint64_t hash_left = 0;
    if (i > 0) {
        hash_left = hash_a[i - 1];
    }
    int ans = 0;
    while(left <= right) {
        int mid = (left + right ) / 2;
        uint64_t hash1 = hash_a[mid] - (hash_left * powers[mid - i + 1]);
        uint64_t hash2 = hash_b[mid - i];
        if (hash1 == hash2) {
            ans = mid - i + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }
    return ans;
}

int main() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::string A, B;
    std::cin >> A >> B;
    std::vector<uint64_t> hash_a (A.size(), 0);
    std::vector<uint64_t> hash_b (B.size(), 0);
    std::vector<uint64_t> powers (std::max(A.size(), B.size()) + 1, 1);
    for (int i = 1; i < powers.size(); ++i) {
        powers[i] = powers[i - 1] *  prime;
    }
    for(int i = 0; i < hash_a.size(); ++i) {
        hash_a[i] = A[i];
        if (i > 0)
            hash_a[i] += (hash_a[i - 1] * prime);
    }
    for (int i = 0; i < hash_b.size(); ++i) {
        hash_b[i] = B[i];
        if (i > 0)
            hash_b[i] += (hash_b[i - 1] * prime);
    }
    std::unordered_map<int, int> matches;
    for (int i = 0; i < hash_a.size(); ++i) {
        int k = calcMatch(i, hash_a, hash_b, powers);
        matches[k] += 1;
    }
    for (int i = 0; i < Q; ++i) {
        int k ;
        std::cin >> k;
        if (matches.count(k)) {
            std::cout << matches[k] << std::endl;
        } else{
            std::cout << 0 << std::endl;

        }
    }


}