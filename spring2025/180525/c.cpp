#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Point {
    int b = -1;
    bool u = false;
};

int res = INT_MAX;
int n;

void task(vector<vector<Point>>& u, int x, int y, int maxVal) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        res = min(res, maxVal);
        return;
    }

    if (u[x][y].b == -1 || u[x][y].u) {
        return;
    }

    int newMaxVal = max(maxVal, u[x][y].b);

    if (newMaxVal >= res) {
        return;
    }

    u[x][y].u = true;

    task(u, x-1, y, newMaxVal);
    task(u, x+1, y, newMaxVal);
    task(u, x, y-1, newMaxVal);
    task(u, x, y+1, newMaxVal);

    u[x][y].u = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    vector<vector<Point>> u(n, vector<Point>(n));
    for (auto [x, y] : a) {
        u[x][y].b = 0;
    }
    for (int t = 1; t <= k; ++t) {
        int x, y;
        cin >> x >> y;
        u[x][y].b = t;
    }

    for (auto [x, y] : a) {
        if (x == 0 || x == n-1 || y == 0 || y == n-1) {
            cout << 0 << '\n';
            return 0;
        }
    }

    for (auto [x, y] : a) {
        task(u, x, y, 0);
    }

    cout << res << '\n';
}