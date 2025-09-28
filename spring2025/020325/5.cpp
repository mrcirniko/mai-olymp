#include <iostream>
#include <vector>

using namespace std;

void generateExchanges(int n) {
    int rounds = (n % 2 == 0) ? n - 1 : n; // Number of rounds
    cout << rounds << endl;

    for (int r = 0; r < rounds; ++r) {
        vector<pair<int, int>> exchanges;

        // Pair person 1 with someone
        int partner = (r + 1) % n + 1;
        exchanges.push_back({1, partner});

        // Pair the remaining people
        for (int i = 1; i < n / 2; ++i) {
            int a = (r + i + 1) % n + 1;
            int b = (r + n - i) % n + 1;
            if (a == 0) a = n;
            if (b == 0) b = n;
            exchanges.push_back({a, b});
        }

        // Output the exchanges for this round
        cout << exchanges.size() << endl;
        for (auto& p : exchanges) {
            cout << p.first << " " << p.second << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    generateExchanges(n);
    return 0;
}