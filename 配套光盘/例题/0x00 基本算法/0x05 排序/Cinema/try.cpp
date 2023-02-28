#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
struct Movie {
    uint64_t _index;
    uint64_t _audio_number = 0;
    uint64_t _cc_number = 0;
};

int main() {
    uint64_t n;
    std::cin >> n;
    std::unordered_map<uint64_t, uint64_t> language_n_people;
    for (uint64_t i = 1; i <= n; ++i) {
        uint64_t lan ;
        std::cin >> lan;
        language_n_people[lan] += 1;
    }
    uint64_t m;
    std::cin >> m;
    std::vector<Movie> movies(m, Movie{});
    for (uint64_t i = 0; i <m; ++i) {
        uint64_t lan;
        std::cin >> lan;
        movies[i]._index = i;
        movies[i]._audio_number = language_n_people[lan];
    }
    for (uint64_t i = 0; i <m; ++i) {
        uint64_t lan;
        std::cin >> lan;
        movies[i]._cc_number = language_n_people[lan];
    }
    Movie max;
    for (uint64_t i = 0; i < m; ++i) {
        if (max._audio_number > movies[i]._audio_number) continue;
        if (movies[i]._audio_number > max._audio_number) {
            max = movies[i];
            continue;
        }
        if (movies[i]._cc_number > max._cc_number) {
            max = movies[i];
        }
    }
    std::cout << max._index + 1 << std::endl;


}