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
    ll  p[n];
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    ll fac = fact(n);
    std::vector<std::vector<ll>> a(fac, std::vector<ll> (n));
    ll size=0;
 
    for(int i = 0; i < fac; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0){
                a[i][j] = j + 1;
            }
            else{
                a[i][j] = a[i - 1][p[j] - 1];
            }
            bool f=0;
            if(i != 0){
                for(int k = 0; k < n; ++k) {
                    if (a[i][k] != a[0][k]) {
                        f=1;
                    }
                }
            }
            if (!f && i != 0) {
                size = i;
                break;
            }
        }
    }
   // for(int i = 0; i < n; ++i){
     //   for(int j = 0; j < n; ++j){
       //     cout << a[i][j] << ' ';
      //  }
    //    cout << "\n";
 //   }
              
      
    int start_i;
    if(U % n == 0){
        start_i = size - 1; 
    }
    else{
        start_i = (U % size) - 1;
    }
  //  cout << "start_i" << start_i << "ffffff\n";
    int answ = 0;
    for(int i = start_i, count = 0; count < D - U + 1; ++count){
        ++answ;
        for(int j = L - 1; j < R; ++j){
         //  cout << a[i][j] << " " << i << " " << j << "     ";
            if(a[i][j] != j + 1){
                --answ;
                break;
            }
        }
     //   cout << endl;
        ++i;
        if(i == size){
            i = 0;
        }
    }
    cout << answ;
}