#include <bits/stdc++.h>
#define RES 1000000000000000003

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == 0 || b == 0) {
            cout << -1 << '\n';
        } else {
            cout << RES << '\n';
        }
    }
}
