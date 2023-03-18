#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

int temp, n, w, res, arr[MAXN][3], dp[MAXN][31][3]; //dp[i][j][k]는 i초 시점에서 j번 움직여서 k 위치의 나무에 있었을 때 먹을 수 있는 자두의 최대 갯수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w;

    loop(i, 1, n){
        cin >> temp;
        if(temp == 1) arr[i][1]++;
        else arr[i][2]++;
    }
    loop(i, 1, n){
        dp[i][0][1] = dp[i - 1][0][1] + arr[i][1];
        loop(j, 1, w){
            dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + arr[i][1];
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + arr[i][2];
        }
    }
    loop(j, 1, w){
        res = max(res, max(dp[n][j][1], dp[n][j][2]));
    }
    cout << res;
}