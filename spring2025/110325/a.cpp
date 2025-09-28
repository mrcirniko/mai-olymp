#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> l(26, 0);
    for (char c : s) {
        ++l[c - 'a'];
    }
    bool odd = 1;
    bool even = 1;
    for (auto el : l) {
        if (el != 0) {
            if (el % 2 == 0) {
                odd = 0;
            } else {
                even = 0;
            }
        }
    }
    if (odd) {
        cout << '1' << '\n';
    } else if (even) {
        cout << '0' << '\n';
    } else {
        cout << "0/1" << '\n';
    }
}