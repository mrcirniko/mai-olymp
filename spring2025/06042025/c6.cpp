#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 

template <typename T>
T fact(T n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    T result = 1;
    for (T i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    ll  n, U, D, L, R;
    cin >> n >> U >> D >> L >> R;
    int  p[n];
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    ll fac = fact(n);
    std::vector<std::vector<int>> a(fac, std::vector<int> (n));
     
    ll size=0;
 
    for(int i = 0; i < fac; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0){
                a[i][j] = j + 1;
            }
            else{
                a[i][j] = a[i - 1][p[j] - 1];
            }
        }
        bool f=0;
        if(i != 0){
            for(int k = 0; k < n; ++k) {
                if (a[i][k] != a[0][k]) {
                    f=1;
                    break;
                }
            }
        }
        if (!f && i != 0) {
            size = i;
            break;
        }
    }
    if (size==0) {
        ++size;
    }
   // for(int i = 0; i < n; ++i){
     //   for(int j = 0; j < n; ++j){
       //     cout << a[i][j] << ' ';
      //  }
    //    cout << "\n";
 //   }
              
      
    int start_i;
    if(U % size == 0){
        start_i = size - 1; 
    }
    else{
        start_i = (U % size) - 1;
    }

    std::vector<int> aa(n);
    std::vector<int> b(n);
    aa = a[start_i];
 
    ll answ = 0;
    if(U == 1){
        ++answ;
    }
    for(ll i = U; i <= D; ++i){
        for(ll j = 0; j < n; ++j){
            b[j] = aa[p[j] - 1];
        }
        ++answ;
        for(ll j = L - 1; j < R; ++j){
            if(b[j] != j + 1){
                --answ;
                break;
            }
        }
        swap(aa, b);
    }
    cout << answ;
}