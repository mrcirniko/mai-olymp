#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll llmax(ll a, ll b) {
    return (a>b) ? a : b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    vector<int> m(k);
    vector<int> c(n);
    for (int i=0;i<k;++i) {
        cin >> m[i];
    }
    sort(m.begin(), m.end());
    int sum = 0;

    for (int i=0;i<n;++i) {
        cin >> c[i];
        sum += c[i];
    }

}
