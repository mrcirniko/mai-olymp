#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int res = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 1; k < min(n - j, n - i); ++k) {
                int c = 0;
                int h = 0;
                if (a[i][j] == a[i][j + k] && a[i][j] == a[i + k][j] && a[i][j] < a[i + k][j + k]) {
                    res = max(res, a[i][j]);
                }
                if (a[i][j] == a[i][j + k] && a[i][j] < a[i + k][j] && a[i][j] == a[i + k][j + k]) {
                    res = max(res, a[i][j]);
                }
                if (a[i][j] < a[i][j + k] && a[i][j] == a[i + k][j] && a[i][j] == a[i + k][j + k]) {
                    res = max(res, a[i][j]);
                }
                if (a[i][j] > a[i][j + k] && a[i][j + k] == a[i + k][j] && a[i][j + k] == a[i + k][j + k]) {
                    res = max(res, a[i][j + k]);
                }
            }
        }
    }
    cout << res << '\n';
}