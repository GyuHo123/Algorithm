#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001
#define Mod 1000000000

using namespace std;

ll dp[MAXN]; // dp[i] = "i를 멱수의 합으로 나타낼 수 있는 경우의 수"
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1] = 1, dp[2] = 2, dp[3] = 2;
    loop(i, 4, n){
        dp[i] = (dp[i - 2] + dp[(int)i / 2]) % Mod;
    }
    cout << dp[n] % Mod << endl;
}