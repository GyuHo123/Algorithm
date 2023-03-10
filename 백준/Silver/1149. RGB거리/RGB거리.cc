#include<iostream>
#include<stack>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1001
#define Mod 1000000000

using namespace std;

ll n, k, arr[MAXN][4], dp[MAXN][4]; //dp[i][j] = "i번째 집을 j번째 색으로 칠했을 때의 누적 비용"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    loop(i, 1, n)
        loop(j, 1, 3)
            cin >> arr[i][j];
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];
    dp[1][3] = arr[1][3];
    loop(i, 1, n)
        loop(j, 1, 3){
            if(j == 1) dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + arr[i][j];
            else if(j == 2) dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + arr[i][j];
            else dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j - 2]) + arr[i][j];
        }
    cout << min(dp[n][1], min(dp[n][2], dp[n][3]));
}
