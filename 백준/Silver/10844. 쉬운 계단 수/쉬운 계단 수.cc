#include<bits/stdc++.h>
#define endl '\n'
#define Mod 1000000000

using namespace std;

long long dp[101][101];
long long res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    dp[1][0] = 0;

    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if(j == 0) dp[i][j] = dp[i - 1][1] % Mod;
            if(j == 9) dp[i][j] = dp[i - 1][8] % Mod;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
        }
    }



    for(int i = 0; i <= 9; i++){
        res += dp[n][i];
    }

    cout << res % Mod;

}