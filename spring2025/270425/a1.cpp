#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> a_pref(n);
    vector<pair<int, int>> pairs;
    ll i=-1;
    while (cin >> a[++i]) {}
    a_pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        a_pref[i] = a_pref[i - 1] + a[i];
    }
    int r = -1;
    int l = -1;
    ll m = LLONG_MIN;
    int sign = 0;
    for (int i = 0; i < n; ++i) {
        ll mi = LLONG_MIN;
        ll ma = LLONG_MAX;
        



    }
    pairs.push_back({l, r});

    for (auto el : pairs) {
        int l = el.first;
        int r = el.second;
        int cur = l;
        for (int i = l; i <= r; ++i) {
            if (a_pref(cur) - a_pref(l))
        }
    }
    for (auto i : pairs) {
        cout << i.first << ' ' << i.second << '\n'; 
    }

}