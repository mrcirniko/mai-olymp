#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define MAX_INT 1e18

using namespace std;
using ll = long long;

template<typename T>
T my_min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<ll> > c(n + 1, vector<ll>(m + 1, 0));
    ll res = MAX_INT;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> c[i][j];
            if (c[i][j] == -1) {
                c[i][j] = MAX_INT;
            }
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }

    for (ll i = a; i <= n; ++i) {
        for (ll j = b; j <= m; ++j) {
            ll t = c[i][j] + c[i - a][j - b] - c[i - a][j] - c[i][j - b];
            if (t > 0) {
                res = my_min(res, t);
            }
        }
    }
    for (ll i = b; i <= n; ++i) {
        for (ll j = a; j <= m; ++j) {
            ll t = c[i][j] + c[i - b][j - a] - c[i - b][j] - c[i][j - a];
            if (t > 0) {
                res = my_min(res, t);
            }
        }
    }

    cout << (res >= MAX_INT ? -1 : res) << endl;
}