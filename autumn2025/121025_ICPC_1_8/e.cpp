#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> a;
ll solve(ll i, ll k, ll d) {
    ll aii = (k == i+1) ? a[i+1] + d : a[i+1];
    if (i != 0) {
        return (solve(i-1, k, d) - 2*aii) % 7 == 0 ? 1 : 0;
    }
    return (a[i] - 2*aii) % 7 == 0 ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    ll res = 0;
    cin >> s;
    ll n = (ll)s.size();
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    for (ll i = 0; i < n; ++i) {
        if (a[i]!=0) {
            res+=(ll)solve(n-1, i, -1);
        }
        res+=(ll)solve(n-1, i, 1);
    }
    cout << res;
}