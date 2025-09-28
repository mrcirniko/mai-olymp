#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = 0;
    if (s[2] == ':') {
        cout << (s[7] - '0') + 10 * (s[6] - '0') + 60 * (s[4] - '0') + 600 * (s[3] - '0') + 3600 * (s[1] - '0') + 36000 * (s[0] - '0');
    } else {
        int k = 1;
        std::reverse(s.begin(), s.end());
        for (auto e : s) {
            n += (e - '0') * k;
            k *= 10;
        }
        int h, m, sec;
        h = n / 3600;
        m = (n % 3600) / 60;
        sec = n % 60;
        
        cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << ":" << (sec < 10 ? "0" : "") << sec;
    }
    return 0;
}