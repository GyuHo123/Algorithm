#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 201
#define Mod 1000000000

using namespace std;

int n, k;
ll dp[MAXN][MAXN];//dp[i][j] = "j개의 수를 더해서 i가 되는 경우의 수의 개수"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    loop(i, 1, k)
        dp[1][i] = i;
    loop(i, 2, n)
        loop(j, 1, k)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % Mod;
    cout << dp[n][k] % Mod;
}
