#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> dp(n + 1);

    for(int i = 2; i <= n; i++) {
       dp[i] = dp[i - 1] + 1;
       if(!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
       if(!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[n] << endl;
}