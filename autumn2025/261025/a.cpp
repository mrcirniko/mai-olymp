#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(26, 0);
    string s;
    cin >> s;
    for (auto c : s) {
        ++v[c-'a'];
    }
    cout <<'\n';
    int n = 0;
    for (int e : v) {
        if (e % 2 != 0) {
            if (n>=1) {
                cout << "no";
                return 0;
            }
            ++n;

        }
    }
    cout << "yes";
}