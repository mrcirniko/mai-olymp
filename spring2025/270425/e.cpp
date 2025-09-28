#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> s1(n,vector<char>(n));
    vector<vector<char>> s2(n,vector<char>(n));
    vector<vector<char>> p(3,vector<char>(3));
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> p[i][j];
            s1[i][j] = p[i][j];
            cout << s1[i][j];
        }
    }
    
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << s1[i][j];
        }
        cout << endl;
    }
    return 0;
    
    
}