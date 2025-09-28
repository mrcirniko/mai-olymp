#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int a=0;
    
    string s;
    cin >> n >> s;
    int b=n-1;
    int c = 0;
    string res = "YES";
    for (int i=0;i < n / 2; ++i) {
        if (s[a] != s[b]) {
            c++;
        }
        if (c > 1) {
            res = "NO";
            break;
        }
        a++;
        b--;
    }
    cout << res << endl;
    return 0;
}