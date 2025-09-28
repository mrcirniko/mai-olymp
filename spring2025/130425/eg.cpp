#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
using ll = long long;

vector<bool> sieve(int n) {
    vector<bool> a(n, true);
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i * i <n; ++i) {
        if (a[i]) {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
    return a;
}

bool has_zero(int x) {
    while (x) {
        if (x % 10 == 0)
            return true;
        x /= 10;
    }
    return false;
}

bool check(int x, const vector<bool>& a) {
    if (has_zero(x)) {
        false;
    }
    int d = 1;
    while (d <= x) {
        d *= 10;
    }

    while (x > 0) {
        if (!a[x]) {
            return false;
        }
        d /= 10;
        x %= d;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> a = sieve(n);
    int res = 0;
    for (int i = 2; i < n; ++i) {
        if (a[i] && check(i, a)) {
            res++;
        }
    }
    cout << res << endl;
}
