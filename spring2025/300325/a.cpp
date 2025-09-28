#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

const ll MAX_DEL = 1000000000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        ll n;
        ll res = 0;
        cin >> n;

        for (ll j = 1; j <= n / MAX_DEL; ++j) {
            if (n % j == 0) {
                res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
