#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n, k;
    cin >> n >> k;
    if (n > 1) {
        cout << (double)(1+(n-1)*(k-1))/n;
    } else {
        cout << 1.0;
    }
}