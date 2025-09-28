#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    int n, r, a, b, c;
    cin >> n >> r;
    double res = 0.0;
    cout << fixed << setprecision(6);
    for (int i=0;i < n; ++i) {
        cin >> a >> b >> c;

        double alpha = asin(2.0 * sqrt(r*r - (c*c / (double)(a*a + b*b))) / (r * 2.0)) * 2.0;
        
        double p = (alpha - sin(alpha)) / (4.0 * acos(0.0));
        p = min(p, 1 - p);
        res = p > res ? p : res;
        //cout << alpha << ' ' << p << ' ' << res << endl;
    }

    
    cout << res << ' ' << 1 - res << endl;
}