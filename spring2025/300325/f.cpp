#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int num : a) {
        cout << bitset<30>(num) << endl;
    }
    for (int num : a) {
        if (num <= 5 && num >= 2) {
            cout << bitset<30>(num ^ 1) << endl;
        } else {
            cout << bitset<30>(num) << endl;
        }
        
        
    }
    cout << endl;

    return 0;
}
