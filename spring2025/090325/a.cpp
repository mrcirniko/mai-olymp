#include <iostream>
#include <vector>
#include <algorithm>


#define MAX_INT 1e18

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll> > a(4, vector<ll>(4));
    vector<char> res;
    ll old = -1;
    ll count = 0;
    bool f = false;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j];

            if (f) {
                if (j == 0 && i != 0) {
                    res.push_back('L');
                } else {
                    res.push_back('U');
                }
            }
            if (a[i][j] == 0) {
                f =true;
            }
            if (a[i][j] != 0 && a[i][j] < old) {
                cout << "No" << '\n';
                return 0;
            }
            old = a[i][j];
        }
    }
    cout << "Yes" << '\n'<< res.size() << '\n';
    std::reverse(res.begin(), res.end());
    for (auto el: res) {
        cout << el << '\n';
    }
    return 0;
}

