#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>

using ull = unsigned long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ull> a(n);
    int k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ull arr[62];
    for (int i = 0; i <= 61; ++i) {
        arr[i] = i == 64 ? 0 : (1 << i);
    }

    ull res = ULLONG_MAX;

    for (int l = 0; l <= 60; ++l) {
        ull c = 0;
        ull xxor = 0;
        ull m = (arr[l+1] - 1);

        for (int i = 0; i < n; ++i) {
            ull x = a[i];
            if ((x >> l) & 1) {
                xxor ^= x;
                continue;
            }
            ull t = x & m;
            if (x >= arr[l+1]) {
                ull j = arr[l] - t;
                ull d = t + 1;
                if (d < j) {
                    c += d;
                    xxor ^= (x - d);
                    
                } else {
                    c += j;
                    xxor ^= (x + j);
                }
            } else {
                ull j = arr[l] - t;
                c += j;
                xxor ^= (x + j);
            }
        }
        if (n % 2 == 1) {
            res = min(res, c);
        } else {
            res = min(res, c + (xxor == 0 ? 1 : 0));
        }
    }

    cout << res;
}
