#include<bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001
#define ll long long
#define endl '\n'
#define Mod 9901

using namespace std;

int n, dp[MAXN][4], tempRes; //dp[i][0] = "i번째 줄에서의 사자를 배치할 수 있는 모든 경우의 수"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][0] = 3;

    loop(i, 2, n){
        tempRes = 0;
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % Mod;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % Mod;
        dp[i][3] = (dp[i - 1][1] + dp[i - 1][2]) % Mod;
        dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % Mod;
    }

    cout << dp[n][0];
}