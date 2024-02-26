#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1025

using namespace std;

int X1, Y1, X2, Y2;

int arr[MAXN][MAXN];

int dp[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    loop(i, 1, n){
        loop(j, 1, n){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    while(m--){
        cin >> X1 >> Y1 >> X2 >> Y2;
        int sum = dp[X2][Y2] - dp[X2][Y1-1] - dp[X1-1][Y2] + dp[X1-1][Y1-1];
        cout << sum << endl; 
    }
}