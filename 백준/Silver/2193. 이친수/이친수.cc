#include<bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 90
#define ll long long
using namespace std;

ll n, dp[MAXN][2], res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;

    loop(i, 2, n){
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
        dp[i][1] = dp[i - 1][0];
    }
    res = dp[n][0] + dp[n][1];
    cout << res;
}