#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001

using namespace std;

int n;
int dp[4][2];
int temp[4][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a1, a2, a3;

    cin >> a1 >> a2 >> a3;

    dp[1][0] = dp[1][1] = a1;
    dp[2][0] = dp[2][1] = a2;
    dp[3][0] = dp[3][1] = a3;

    loop(i, 2, n) {
        cin >> a1 >> a2 >> a3;

        temp[1][0] = a1 + max(dp[1][0], dp[2][0]);
        temp[1][1] = a1 + min(dp[1][1], dp[2][1]);

        temp[2][0] = a2 + max({dp[1][0], dp[2][0], dp[3][0]});
        temp[2][1] = a2 + min({dp[1][1], dp[2][1], dp[3][1]});

        temp[3][0] = a3 + max(dp[2][0], dp[3][0]);
        temp[3][1] = a3 + min(dp[2][1], dp[3][1]);

        dp[1][0] = temp[1][0];
        dp[1][1] = temp[1][1];
        dp[2][0] = temp[2][0];
        dp[2][1] = temp[2][1];
        dp[3][0] = temp[3][0];
        dp[3][1] = temp[3][1];
    }

    int maxScore = max({dp[1][0], dp[2][0], dp[3][0]});
    int minScore = min({dp[1][1], dp[2][1], dp[3][1]});

    cout << maxScore << " " << minScore;
}
