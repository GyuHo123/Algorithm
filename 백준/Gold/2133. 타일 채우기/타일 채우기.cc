#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i += 2)
#define LOOP(i, s, n) for(int i = s; i < n; i += 2);
#define MAXN 31

using namespace std;

int n, dp[MAXN]; // dp[i] = 3 * i 패널을 채울 수 있는 경우의 수의 개수

int main(){
    dp[1] = 0, dp[2] = 3;
    
    cin >> n;
    
    loop(i, 4, n){
        dp[i] = dp[i - 2] * dp[2];
        for(int j = i - 4; j > 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] += 2;
    }
    cout << dp[n];
}