#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m, n, k;
    cin >> m >> n >> k;
    if (m % k == 0 || n % k == 0) {
        cout << "YES";

    } else {
        cout << "NO";
    }
}