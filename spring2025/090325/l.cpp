#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char> > a(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'C' && (a[i + 1][j] == 'R' || a[i - 1][j] == 'R' || a[i][j + 1] == 'R' || a[i][j - 1] == 'R')) {
                cout << "No" << '\n';
                //<< ' ' << i << ' ' << j << a[i][j] <<'\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '.') {
                cout << '#';
            } else {
                cout << a[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
    
}
