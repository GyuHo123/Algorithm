#include <bits/stdc++.h>
#define ll long long
#define MAXN 36
#define endl '\n'

using namespace std;

ll dp[MAXN]; // dp[n] = "Σ t(k) * t(n-1-k)"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    int n;
    cin >> n;

    cout << dp[n] << endl;
}
