#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

//using namespace std;
using ll = long long;

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

    std::unordered_map<std::bitset<6>, int> a_count;
    for (const auto& bits : a_binary) {
        a_count[bits]++;
    }

    std::vector<int> res(m, 0);
    std::vector<bool> bin(m, false);

    for (int k = 0; k < m; ++k) {
        std::bitset<6> t;
        for (const auto& [bits, count] : a_count) {
            std::bitset<6> t1 = bits & b_binary[k];
            if (t1.any()) {
                res[k] += count;
                t |= t1;
            }
        }
        bin[k] = (t & b_binary[k]) == t;
    }

    for (int i = 0; i < m; ++i) {
        std::cout << res[i] << ' ' << bin[i] << '\n';
    }

    return 0;
}