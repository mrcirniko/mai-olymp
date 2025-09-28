#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

using ll = long long;

bool compare(const int a, const int b) { 
    return a > b; 
}

const int MOD = 998244353;

int mod(const vector<int>& a) {
    long long res = 0;
    for (int d : a) {
        res = (res * 10 + d) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a;
    vector<int> b;
    char ch;
    int f = 0;
    while ((ch = cin.get()) != EOF) {
        if (ch == '\n') {
            ++f;
            if (f == 2) break;
        } else {
            if (f == 0) a.push_back(ch - '0');
            else if (f == 1) b.push_back(ch - '0');
        }
    }

    if (a.size() < b.size()) {
        swap(a,b);
    }


    vector<int> c;
    c.reserve(a.size() + b.size());
    c.insert(c.end(), a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());
    sort(c.begin(), c.end(), compare);
    vector<int> newa;
    if (a.size() > b.size()) {
        newa.assign(c.begin(), c.begin() + (a.size() - b.size()));
    }
    vector<int> newb;
    bool f1 = 0;
    for (int i = max(0, (int)(a.size() - b.size())); i < (int)c.size(); ++i) {
        if (f1) {
            newa.push_back(c[i]);
            f1 = 0;
        } else {
            newb.push_back(c[i]);
            f1 = 1;
        }
    }
    int amod = mod(newa);
    int bmod = mod(newb);
    int res = (amod + bmod) % MOD;

    cout << res;
}