#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 101;
const int MAXK = 100001;
int N, K, result;
int walk[MAXN][2], cycle[MAXN][2];
int dp[MAXN][MAXK];

int main() {
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> walk[i][0] >> walk[i][1] >> cycle[i][0] >> cycle[i][1];
    }

    for(int i=0; i<=K; i++) {
        dp[0][i] = -1;
    }
    dp[0][0] = 0;

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=K; j++) {
            dp[i][j] = -1;
            if (j >= walk[i][0] && dp[i-1][j-walk[i][0]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-walk[i][0]] + walk[i][1]);
            }
            if (j >= cycle[i][0] && dp[i-1][j-cycle[i][0]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-cycle[i][0]] + cycle[i][1]);
            }
        }
    }
    for(int i=0; i<=K; i++) {
        result = max(result, dp[N][i]);
    }

    cout << result << endl;
}
