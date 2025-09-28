#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_INT 1e18

using namespace std;
using ll = long long;

template<typename T>
T my_min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    ll m, n ,a, b;
    cin >> n >> m >> a >> b;
    vector<vector<ll> > c(n, vector<ll>(m, 0));
    ll res = MAX_INT;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            if (c[i][j] == -1) {
                c[i][j] = MAX_INT;
            }
            if (i > 0 and j > 0) {
                c[i][j] += c[i-1][j] + c[i][j-1] - c[i-1][j-1];
            } else if (i > 0) {
                c[i][j] += c[i-1][j];
            } else if (j > 0) {
                c[i][j] += c[i][j-1];
            }
        }
    }

    
    for (int i = 0; i < n - a; ++i) {
        for (int j = 0; j < m - b; ++j) {
            res = min(res, c[i][j] - c[i + a][j] - c[i][j + b] + c[i + a][j + b]);
        }
    }

    for (int i = 0; i < n - b; ++i) {
        for (int j = 0; j < m - a; ++j) {
            res = min(res, c[i][j] - c[i + b][j] - c[i][j + a] + c[i + b][j + a]);
        }
    }

    cout << (res == MAX_INT ? -1 : res) << endl;
}


/*#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long getSum(const vector<vector<long long>>& prefix, int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<long long>> grid(n+1, vector<long long>(m+1, 0));
    vector<vector<long long>> prefix(n+1, vector<long long>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> prefix[i][j];
            if (prefix[i][j] == -1) {
                prefix[i][j] = LLONG_MAX; // Treat occupied cells as 0 cost
            }
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + prefix[i][j];
        }
    }

    long long minCost = LLONG_MAX;

    // Check for a x b rectangle
    for (int i = 1; i <= n - a + 1; ++i) {
        for (int j = 1; j <= m - b + 1; ++j) {
            long long sum = getSum(prefix, i, j, i+a-1, j+b-1);
            if (sum > 0) {
                minCost = min(minCost, sum);
            }
        }
    }

    // Check for b x a rectangle
    for (int i = 1; i <= n - b + 1; ++i) {
        for (int j = 1; j <= m - a + 1; ++j) {
            long long sum = getSum(prefix, i, j, i+b-1, j+a-1);
            if (sum > 0) {
                minCost = min(minCost, sum);
            }
        }
    }

    if (minCost == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}*/