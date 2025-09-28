#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<char> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll p_count = 0;
    ll max_p_count = 0;
    for (auto el : a) {
        if (el == 'P' || el == 'p') {
            max_p_count = max(max_p_count, ++p_count);
        } else {
            p_count = 0;
        }
    }

    ll res = 0;
    while(!a.empty() && (a[0] ==  'F' || a[a.size()-1] == 'F' || a[0] ==  'f' || a[a.size()-1] == 'f')) {
        if (a[0] ==  'F') {
            a.erase(a.begin());
        } else {
            a.pop_back();
        }
        res++;
    }
    
    if (!a.empty()) {
        res += 2 * std::count(a.begin(), a.end(), 'F');
        res += 2 * std::count(a.begin(), a.end(), 'f');
    }

    cout << min(res, n - max_p_count) << '\n';
}