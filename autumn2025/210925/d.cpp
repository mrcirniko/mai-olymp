#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
        cin >> a[i];

    int x = a[0];
    int y = a[1];
    int r = a[2];

    int sum = 1;

    if (x * x + y * y < r * r) {
        cout << 5;
        return 0;
    }

    if (r - y > 0)
        sum++;

    if (r - x > 0)
        sum++;

    if (r - x == 0 || r - y == 0)
        sum++;

    cout << sum;

    return 0;
}
