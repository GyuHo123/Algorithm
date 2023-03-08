#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001
#define Mod 10007

using namespace std;

int n, dp[MAXN][11];// dp[i][j] = 길이가 i일때 끝이 j인 수에서 오르막 수가 될 수 있는 경우의 수의 개수

int main(){
    cin >> n;
    loop(i, 1, 10) dp[1][i] = 1;
    loop(i, 2, n)
        loop(j, 1, 10) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % Mod;
    loop(i, 1, 10) dp[n][0] += dp[n][i];
    cout << dp[n][0] % Mod;
}