#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a;
    int k;
    while(cin >> k) {
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    do {
        if (a[1]*3 + a[2] == a[4] && a[1] + a[2] + a[3] == a[0]) {
            for(auto el : a) {
                cout << el << ' ';
            }
            cout << '\n';
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));
}