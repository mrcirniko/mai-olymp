#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll llmax(ll a, ll b) {
    return (a>b) ? a : b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,b,c, a1, b1, c1;
    cin >> n >> a >> b >> c;
    c1=c;
    b1=b;
    a1=a;
    int res = 0;
    //res = ((a = 0 && b = 0)||(a = 0 && c = 0)||(c = 0 && b = 0)) ? max(a+b+c-n, a+b+c);
    int res1 = min(min(a1, b1), c1);
    a1 -= res1;
    b1 -= res1;
    c1 -= res1;
    res1 += min(n, a1) + min(n, b1) + min(n, c1) + min(min(a1, b1), c1);;
    if (res1>=a+b+c) {
        cout << a+b+c << '\n';
        return 0;
    }


}