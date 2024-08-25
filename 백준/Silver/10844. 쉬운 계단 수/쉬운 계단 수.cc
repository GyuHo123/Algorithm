#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define ll long long
#define MAXN 101
#define MOD 1000000000

int n;
ll dp[MAXN][10], ans;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, 9){
        dp[1][i] = 1;
    }

    loop(i, 2, n){
        dp[i][0] = dp[i - 1][1] % MOD;
        loop(j, 1, 9){
            if(j == 9) dp[i][j] = dp[i - 1][j - 1] % MOD;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD; 
        }
    }
    loop(i, 0, 9){
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans;
}
