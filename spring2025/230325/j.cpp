#include <iostream>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int k = 0;
    for(int i = 0; i < n - 1; ++i){
        if(a[i] > a[i+1]){
            ++k;
        }
    }
    if(k){
        ++k;
    }
    cout << k;
}