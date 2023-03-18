#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1500001
using namespace std;

int n, period[MAXN], arr[MAXN], dp[MAXN];// dp[i] = i - 1번째 날까지 일을 했을 때 벌 수 있는 최대 금액

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> period[i] >> arr[i];
    }

    loop(i, 1, n) {
        dp[i + period[i]] = max(dp[i] + arr[i], dp[i + period[i]]);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
    cout << dp[n + 1];
}