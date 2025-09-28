#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll  n, U, D, L, R;
    cin >> n >> U >> D >> L >> R;
    int  p[n];
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    std::vector<std::vector<int>> a;
    
    ll size=0;

    for(int i = 0; i < D; ++i){
        a.push_back(std::vector<int>(n));
        ++size;
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
            a.resize(size);
            break;
        }
    }
    if (size==0) {
        ++size;
    }
  //  for(int i = 0; i < size; ++i){
  //      for(int j = 0; j < n; ++j){
     //       cout << a[i][j] << ' ';
    //    }
       // cout << "\n";
  //  }
             
     
    int start_i;
    if(U % size == 0){
        start_i = size - 1; 
    }
    else{
        start_i = (U % size) - 1;
    }
  //  cout << "start_i" << start_i << "ffffff\n";
    int answ = 0;
    ll count = 0;
    for(int i = start_i; count < D - U + 1; ++count){
        ++answ;
        for(int j = L - 1; j < R; ++j){
        //   cout << a[i][j] << " " << i << " " << j << "     ";
            if(a[i][j] != j + 1){
                --answ;
                break;
            }
        }
       // cout << endl;
        ++i;
        if(i == size){
            i = 0;
        }
    }
    cout << answ;
}