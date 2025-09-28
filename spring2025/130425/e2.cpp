#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
using ll = long long;

vector<char> sieve(int n) {
    vector<char> a(n, 1);
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i * i < n; ++i) {
        if (a[i]) {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
    return a;
}

bool check(int x, const vector<char>& a) {
    int y = x;
    int z = 1;
    while (y >= 10) {
        if ((y % 10) == 0) {
            return false;
        }
        y /= 10;
        z *= 10;
    }
    if ((y % 10) == 0) {
        return false;
    }

    while (z > 0) {
        if (!a[x]) {
            return false;
        }
        x %= z;
        z /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char> a = sieve(n);
    int res = 0;
    for (int i = 2; i < n; ++i) {
        if (a[i] && check(i, a)) {
            res++;
        }
    }
    cout << res << endl;
}
