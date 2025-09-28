#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> a >> b;
    int res = a%b != 0 ? a/b + max(0, (int)log2(a%b)) - 1 + a%b :  a/b + max(0, (int)log2(b)) - 1;
    cout << res << '\n';
}