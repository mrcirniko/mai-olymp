#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll a = n / 4;
    ll b = n /5;
    ll c = n/6;
    ll res = a+b+c;
    res -= 2*(n/20 + n/12 + n/30);
    res += 3*(n/60);
    cout << res;
}