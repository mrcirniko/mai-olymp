#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b){
    while(b){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    float n;
    int res = 1;
    for(int i = 0; i < 14; ++i){
        cin >> n;
        t = n * 10;
        res = res / solve(res, 1000 / solve(1000, t)) * 1000 / solve(1000, t);
    }
    cout << res;
}