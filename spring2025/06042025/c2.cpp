#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
T fact(T n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    T result = 1;
    for (T i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll  n, U, D, L, R;
    cin >> n >> U >> D >> L >> R;
    ll  p[n];
    for(ll i = 0; i < n; ++i){
        cin >> p[i];
    }
    std::vector<ll> a(n);
    std::vector<ll> b(n);
    for(ll j = 0; j < n; ++j){
        a[j] = j + 1;
    }

    ll answ = 0;
    if(U == 1){
        ++answ;
    }
    std::vector<ll> mat(fact(n));
    while(1){
        for(ll j = 0; j < n; ++j){
            b[j] = a[p[j] - 1];
        }

    }
    for(ll i = 2; i <= D; ++i){
        for(ll j = 0; j < n; ++j){
            b[j] = a[p[j] - 1];
        }
        if(i >= U){
            ++answ;
            for(ll j = L - 1; j < R; ++j){
                if(b[j] != j + 1){
                    --answ;
                    break;
                }
            }
        }
        swap(a, b);
    }
    cout << answ;
}
