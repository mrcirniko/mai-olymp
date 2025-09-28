#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll llmax(ll a, ll b) {
    return (a>b) ? a : b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        vector<ll> b(2*n);
        vector<bool> bb(2*n, false);
        vector<ll> a;
        for(int j = 0; j < 2*n; ++j) {
            cin >> b[j];
        }
        sort(b.begin(), b.end());
        a.push_back(b[0]);
        ll cur_sum = b[0];
        ll nearest_sum_idx = 0;
        for(int j = 2; j < 2*n; ++j) {
            if (bb[j]) {
                continue;
            }
            cur_sum+=b[j];
            a.push_back(b[j]);
            nearest_sum_idx = llmax(nearest_sum_idx, j + 1);
            for(int k = nearest_sum_idx; k < 2*n; ++k) {
                if (b[k] == cur_sum) {
                    nearest_sum_idx = k;
                    bb[k] = true;
                    break;
                }
            }

        }
        for (auto el : a) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}