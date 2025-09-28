#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<bool> a(n, false);
    //const int n = 1e6;

    vector<int> d[n+1];
    vector<int> p;
     
    for (int k = 2; k <= n; k++) {
        if (p[k] == 0) {
            d[k] = k;
            p.push_back(k);
        }
        for (int x : p) {
            if (x > d[k] || x * d[k] > n)
                break;
            d[k * x] = x;
        }
    }
    for (auto i : p) {
        cout << i << '\n';
    }
}