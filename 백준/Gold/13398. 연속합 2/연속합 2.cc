#include<bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001
#define ll long long
#define endl '\n'

using namespace std;

int n, arr[MAXN], dp[MAXN][2], res; //dp[i] = "음수인 최소를 제거해 마지막 원소가 arr[i]인 연속합 수열의 최대합", dp[i][j] = "마지막 원소가 arr[i]인 연속합(j번의 크기 만큼 제거)"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    res = arr[1];

    loop(i, 2, n){
        dp[i][0] = max(arr[i] + dp[i - 1][0], arr[i]);
        dp[i][1] = max(arr[i] + dp[i - 1][1], dp[i - 1][0]);
        res = max(res, max(dp[i][0], dp[i][1]));
    }

    cout << res;
}