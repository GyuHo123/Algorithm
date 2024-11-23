#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for (int i = s; i <= n; i++)
#define MAXK 10001

using namespace std;

int n, k, dp[MAXK];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<int> coins(n);
    loop(i, 0, n - 1)
        cin >> coins[i];

    dp[0] = 1;

    for (int coin : coins) {
        loop(i, coin, k) {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[k] << endl;
}
