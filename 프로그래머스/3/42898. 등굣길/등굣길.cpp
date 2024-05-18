#include <bits/stdc++.h>

#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {

    dp[1][1] = 1;

    for (auto puddle : puddles)
        dp[puddle[1]][puddle[0]] = -1;

    loop(i, 1, n){
        loop(j, 1, m){
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if(i > 1) dp[i][j] += dp[i - 1][j] % 1000000007;
            if(j > 1) dp[i][j] += dp[i][j - 1] % 1000000007;
        }
    }
        return dp[n][m] % 1000000007;
}
