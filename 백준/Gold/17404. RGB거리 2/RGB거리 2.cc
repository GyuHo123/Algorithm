#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1001

using namespace std;

ll n, arr[MAXN][4], dp[MAXN][4], res = INT_MAX; //dp[i][j] = "i번째 집을 j번째 색으로 칠했을 때의 누적 비용"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    loop(i, 1, n)
        loop(j, 1, 3)
            cin >> arr[i][j];

    loop(k, 1, 3){
        loop(i, 1, n){
            if(i == k) dp[1][i] = arr[1][i];
            else dp[1][i] = INT_MAX;
        }
        loop(i, 2, n){
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
            dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
        }
        loop(i, 1, 3){
            if(i == k) continue;
            else res = min(res, dp[n][i]);
        }
    }
    cout << res;
}
