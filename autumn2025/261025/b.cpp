#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n;
    cin >> c >> n;

    if (n > c) {
        cout << c+1;
    } else if (n < c) {
        cout << '0';
    } else {
        cout << n;
    }
}