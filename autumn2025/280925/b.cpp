#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n % 2 == 0) {
        return n == 2;
    }
    if (n % 3 == 0) {
        return n == 3;
    }
    for (int i = 5; 1LL * i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (b-a!=2) {
            cout << "N" << '\n';
        } else if (isPrime(a) && isPrime(b)) {
            cout << "Y" << '\n';
        } else {
            cout << "N" << '\n';
        }
    }
}