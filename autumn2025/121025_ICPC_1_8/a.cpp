#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int y, u, s, f, r;
    cin >> y>> u>> s>> f>> r;
    if (f >= 2 || r >= 6) {
        cout << '-';
        return 0;
    }
    if (r == 5 || (y < 2002 && u < 2021)) {
        if (s >= 9) {
            cout << '-';
            return 0;
        }
        cout << '?';
        return 0;
    }
    if (!(y < 2002) || !(u < 2021)) {
        cout << '+';
        return 0;
    }
}

