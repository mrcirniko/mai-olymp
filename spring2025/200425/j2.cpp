#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;
using uint = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<uint, uint>> a(n, {0, 0});
    a[0] = {1, 1};
    for (int i = 1; i < n; ++i) {
        a[i].second = a[i-1].second + 2;
        a[i].first = a[i-1].first + a[i].second;
        cout << a[i].first << ' ';
    }
    int i = n - 1;
    int sq = a[i].first;
    int c = 0;
    bool f=0;
    while(i > 0) {
        if (n == a[i].second + 1 + c) {
            f=1;
            break;
        }
        c += a[i].second;
        --i;
    }
    cout << sq << ' ';
    for (int i = 0; i < c; ++i) {
        cout << 1 << ' ';
    }
    return 0;
}