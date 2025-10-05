#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
vector<int> a;
vector<vector<int>> divs;
vector<int> memoize;

int solve(int k) {
    if (k == 0) {
        return 0;
    }
    int &res = memoize[k];
    if (res != -1) {
        return res;
    }
    res = INF;
    for (int d : divs[a[k]]) {
        if (d > k) {
            continue;
        }
        int v = solve(k - d);
        if (v < INF) {
            res = min(res, v + 1);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    int max_a = 0;
    for (int j = 1; j <= n; ++j) {
        max_a = max(max_a, a[j]);
    }

    divs.assign(max_a + 1, {});
    for (int d = 1; d <= max_a; ++d) {
        for (int v = d; v <= max_a; v += d) {
            divs[v].push_back(d);
        }
    }

    memoize.assign(n + 1, -1);
    int res = solve(n);
    cout << (res >= INF ? -1 : res);
    return 0;
}
