#include <iostream>
#include <vector>
#include <algorithm>


#define MAX_INT 1e18

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n, m, l, r = map(int, input().split())
    a = [int(x) for x in input().split()]
    counter = 0 
    2
    for j in range(n):
        if a[j] >= l and a[j] <= r:
            m -= 1
            counter += 1
        else:
            m -= 2
            counter += 1

    if m < 0:
        print(counter)
    else:
        print("izdak!")
}