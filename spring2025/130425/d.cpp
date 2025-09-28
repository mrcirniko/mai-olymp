#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<map<string, int>> a(k);
    vector<string> in(n);
    
    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        in[i] = c;
        for (int j = 0; j < k; ++j) {
            if (j >= c.size()) break;
            string sub = c.substr(0, j + 1);
            a[j][sub]++;
        }
    }
    auto incopy = in;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (j >= in[i].size()) break;
            string sub = in[i].substr(0, j + 1);
            if (a[j][sub] == 1) {
                incopy[i] = sub;
                break;
            }
        }
    }
    
    for (const auto& s : incopy) {
        cout << s << '\n';
    }
}