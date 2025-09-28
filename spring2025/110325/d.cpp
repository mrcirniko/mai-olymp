#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
using ll = long long;

bool compare(const vector<int> & l, const vector<int> & r) 
{ 
    return l[0] < r[0]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (3));
    for (int i = 0; i < n; ++i) {
        int s,w,h;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), compare);
    int res = a[0][0];
    //cout << res << ' ' << '0' << '\n';
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (a[i][0] - a[i - 1][0] - a[i - 1][1] == 0) {
                res += abs(a[i][2] - a[i - 1][2]);
                //cout << res << ' ' << '2' << '\n';
            } else {
                res += a[i][0] - a[i - 1][0] - a[i - 1][1];
                //cout << res << ' ' << '1' << '\n';
                res += a[i][2] + a[i - 1][2];
                //cout << res << ' ' << '3' << '\n';
            }
        } else {
            res += a[i][2];
            //cout << res << ' ' << '4' << '\n';
        }

        res += a[i][1];
        //cout << res << ' ' << '5' << '\n';
        
    }
    //cout << a[n - 1][2] << ' ' << a[n - 1][0] << ' ' << a[n - 1][1];
    res += a[n - 1][2] + 100 - a[n - 1][0] - a[n - 1][1];
    cout << res << '\n';
}