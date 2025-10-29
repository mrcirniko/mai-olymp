#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l,h;
    cin >> n >> l >> h;
    vector<int> v(n, 0);
    vector<vector<int>> vv(n, new vector<int>());
    for (auto &e : v) {
        cin >> e;
        int k = abs(l - e) / 12;
        while
        }

    vector<int> v(26, 0);
    string s;
    cin >> s;
    for (auto c : s) {
        ++v[c-'a'];
    }
    cout <<'\n';
    int n = 0;
    for (int e : v) {
        if (e % 2 != 0) {
            if (n>=1) {
                cout << "no";
                return 0;
            }
            ++n;

        }
    }
    cout << "yes";
}