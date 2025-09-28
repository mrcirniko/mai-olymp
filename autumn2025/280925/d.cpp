#include <string>
#include <iostream>
#include <vector>
using namespace std;
    
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> m(n, vector<int>(n, 0)); 
        for(int len = 2; len <= n; ++len){
            for (int j = 0; j <= n - len; ++j) {
                int k = j + len - 1;  
                if(s[j] == s[k]){
                    if(len == 2){
                        m[j][k] = 0;
                    }
                    else{
                        m[j][k] = m[j + 1][k - 1];
                    }
                }
                else{
                    m[j][k] = min(m[j + 1][k], m[j][k - 1]) + 1;
                }
            }
        }
        cout << m[0][n-1] << '\n';
    }
}