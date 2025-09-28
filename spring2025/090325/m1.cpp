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
    ll res = 0;
    
    // Пока есть 'F' в начале или конце, удаляем их
    while(!a.empty() && (a[0] == 'F' || a[a.size()-1] == 'F')) {
        if (a[0] == 'F') {
            a.erase(a.begin());
        } else if (a[a.size()-1] == 'F') {
            a.pop_back();  // Более эффективно, чем a.erase(a.end() - 1)
        }
        res++;
    }
    
    // Считаем оставшиеся 'F' (все они в середине)
    if (!a.empty()) {
        res += 2 * std::count(a.begin(), a.end(), 'F');
    }
    
    cout << res << '\n';
}
