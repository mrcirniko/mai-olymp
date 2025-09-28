#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int j = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < 0){
            ++j;
        }
        else{
            break;
        }
    }
   // cout << j << "ffff";
    long long b[n] = {0};
    int m = 0;
    int k = 0;
    long long maxa = 0;
    for(int i = j; i < n; ++i){
     //   cout << '\n';
        for(int i = 0; i <= m; ++i){
          //  cout << b[i] << ' ';
        }
        if(a[i] > 0 && k == 0){
            maxa = max(a[i], maxa);
        }
        if(a[i] < 0 && k == 0){
            b[m] = maxa;
            ++m;
            maxa = a[i];
            k = -1;
        }
        if(a[i] < 0 && k == -1){
            maxa = max(a[i], maxa);
        }
        if(a[i] > 0 && k == -1){
            b[m] = maxa;
            ++m;
            maxa = a[i];
            k = 0;
        }
    }
    if(maxa > 0){
        b[m] = maxa;
    }
 //   for(int i = 0; i <= m; ++i){
      //  cout << b[i] << ' ';
  //  }
   // cout << '\n';
    long long sum = b[0];
    long long last = b[0];
   // long long forw = 0;
    long long ot = 0;
    for(int i = 1; i <= m; ++i){
        if(b[i] < 0){
            ot = b[i];
        }
        if(b[i] > 0){
            if(sum + b[i] + ot > sum || sum - last + b[i] > sum){
                sum = max(b[i] + ot + sum,sum - last + b[i]);
                last = b[i];
            }
            cout << sum << ' ';
        }
        
    }
    cout << '\n';
    cout << sum;
    
}