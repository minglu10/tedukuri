#include <bits/stdc++.h>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

uint64_t findKth(std::vector<uint64_t>& array, int left, int right, int k) {
    if (left == right) {
        assert(k == 0);
        return array[left];
    }
    int rand_n = std::rand() % (right -left + 1) ;
    std::swap(array[left], array[rand_n + left]);
    int v0 = array[left];

    int after_bigger = right + 1;
    for (int i = left; i < after_bigger; ) {
        if (array[i] <= v0) {
            ++i;
            continue;
        } else {
            std::swap(array[i], array[--after_bigger]);
        }
    }
    std::swap(array[left], array[after_bigger - 1]);
    if (after_bigger == left + k + 1) {
        return v0;
    }
    if (after_bigger > left + k + 1) {
        return findKth(array, left, after_bigger - 1, k);
    }
    return findKth(array, after_bigger, right, k - (after_bigger -left));
    
}

int main() {
    std::srand(std::time(NULL));
    int n;
    std::cin >> n;
    std::vector<uint64_t> aa(n, 0);
    for (int i = 0; i < aa.size(); ++i) {
        int c;
        std::cin >> c;
        aa[i] = c;
    }
    
    uint64_t mid_value = findKth(aa, 0, aa.size() - 1, (aa.size() - 1) / 2);
    //std::sort(aa.begin(), aa.end());
    //uint64_t k = aa[(aa.size() - 1) / 2];
    //std::cout << "mid va1: " << mid_value << " , mid val2: " << k << std::endl;
    uint64_t ans = 0;
    for (int i = 0; i < aa.size(); ++i) {
        if (aa[i] >= mid_value) {
            ans += aa[i] - mid_value;
        } else {
            ans += mid_value - aa[i];
        }
    }
    //std::cout << findKth(aa, 0, aa.size() - 1, 0) << std::endl;
    //std::cout << findKth(aa, 0, aa.size() - 1, 3) << std::endl;
    //std::sort(aa.begin(), aa.end());
    //uint64_t ans = 0;
    //int left = 0;
    //int right = aa.size() - 1;
    //while(left <= right) {
    //    ans += (aa[right] - aa[left]);
    //    ++left; -- right;
    //}
    std::cout << ans << std::endl;
}