#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned n, m;
    std::cin >> n >> m;
    std::vector<std::bitset<6>> a_binary(n);
    std::vector<std::bitset<6>> b_binary(m);

    for (int i = 0; i < n; ++i) {
        unsigned x;
        std::cin >> x;
        a_binary[i] = std::bitset<6>(x);
    }
    for (int i = 0; i < m; ++i) {
        unsigned x;
        std::cin >> x;
        b_binary[i] = std::bitset<6>(x);
    }

    std::vector<bool> bin(m, false);
    std::vector<int> res(m, 0);

    for (int k = 0; k < m; ++k) {
        std::bitset<6> t;
        for (int i = 0; i < n; ++i) {
            std::bitset<6> t1 = a_binary[i] & b_binary[k];
            if (t1.any()) {
                res[k]++;
            }
            t |= t1;
        }
        bin[k] = (t & b_binary[k]) == t;
    }

    for (int i = 0; i < m; ++i) {
        std::cout << res[i] << ' ' << bin[i] << '\n';
    }

    return 0;
}