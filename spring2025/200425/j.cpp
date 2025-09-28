#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using uint = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 1" << '\n';
    } else if (n == 2) {
        cout << "3 4 5" << '\n';

    } else if (n > 2) {
        for (int i = 1; i <= n - 1; ++i) {
            cout << '2' << ' ';
        }
        cout << n - 2 << ' ' << n << '\n';
    } else {
        cout << "-1" << '\n';
    }
}