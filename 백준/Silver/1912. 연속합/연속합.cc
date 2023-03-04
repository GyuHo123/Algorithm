#include<bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001
#define ll long long
using namespace std;

ll n, dp[MAXN], arr[MAXN], maxRes;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    loop(i, 1, n){
        dp[i] = max(dp[i], dp[i - 1] + arr[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
}