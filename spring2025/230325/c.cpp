#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ;i < n; ++i) {
        cin >> a[i];
    }
    vector<int> res(n, 0);
    for (int k = 0 ;k < n; ++k) {
        vector<int> px_sum(a[k], 0);
        int res = 0;
        px_sum[0] = n - 1;
        for (int i = 1; i < a[k]; ++i) {
            px_sum[i] += px_sum[i - 1] + a[k] - i - 1;
        }
        cout << px_sum[a[k]-1]*(px_sum[a[k]-1]+1)/2+1 << '\n';
    }
    
}