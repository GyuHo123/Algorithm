#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007;
    }

    cout << dp[n];

}
