#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll  n, U, D, L, R;
    cin >> n >> U >> D >> L >> R;
    ll  p[n];
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    vector<ll> prev(n, 0);
    vector<ll> cur(n, 0);
    int res = 0;
    for (int i = 1; i <= D; ++i) {
        bool flag = true;
        for(int j = 0; j < n; ++j) {
            if (i == 1) {
                cur[j] = j+1;
            } else {
                cur[j] = prev[p[j]-1];
                if (cur[j] != j && j >= L-1 && j < R && i >= U) {
                    flag = false;
                }
                if (flag) {
                    res++;
                }
            }

            prev = cur;

        }
        for(int j = 0; j < n; ++j) {
            cout << cur[j] << ' ';
        }
        cout << '\n';
    }

    cout << res;
}
