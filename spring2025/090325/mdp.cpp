#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <functional>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; i++){
       prefix[i+1] = prefix[i] + (s[i]=='F');
    }
    auto hasF = [&](int i, int j) -> bool {
        return (prefix[j+1] - prefix[i]) > 0;
    };

    vector<vector<int>> dp(n, vector<int>(n, -1));

    function<int(int, int)> solve = [&](int i, int j) -> int {
        if(i > j) return 0;
        if(!hasF(i, j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int best = INF;
        best = min(best, 1 + solve(i+1, j));
        best = min(best, 1 + solve(i, j-1));
        for(int k = i+1; k < j; k++){
            best = min(best, 2 + solve(i, k-1) + solve(k+1, j));
        }
        dp[i][j] = best;
        return best;
    };

    cout << solve(0, n-1) << '\n';
    return 0;
}
