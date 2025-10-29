#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n;

    vector<string> res(n);
    string prev;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        vector<string> v(p);
        for (auto &e : v) {
            cin >> e;
        }
        sort(v.begin(), v.end());
        auto it = lower_bound(v.begin(), v.end(), prev);
        if (it == v.end()) {
            cout << "impossible" << '\n';
            return 0;
        }
        res[i] = *it;
        prev = *it;
    }

    for (auto s : res) {
        cout << s << '\n';
    }
}