#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001

using namespace std;

int a, b, d, n;
int dp[MAXN]; //dp[i] = "i일 때 짚신 벌레의 개체 수"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> d >> n;

    LOOP(i, 0, a) dp[i] = 1;
    loop(i, a, n){
        dp[i] = (dp[i - 1] + dp[i - a]) % 1000;
        if(b <= i) dp[i] = (dp[i] - dp[i - b] + 1000) % 1000;
        dp[i] %= 1000;
    }
    if(n >= d) cout << (dp[n] - dp[n - d] + 1000) % 1000 << endl;
    else cout << dp[n] % 1000 << endl;
}