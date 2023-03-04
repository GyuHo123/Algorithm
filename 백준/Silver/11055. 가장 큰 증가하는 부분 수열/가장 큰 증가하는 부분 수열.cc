#include<bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

int n, maxRes, dp[MAXN], arr[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n) {
        cin >> arr[i];
        dp[i] = arr[i];
        LOOP(j, 1, i)
            if (arr[i] > arr[j]) dp[i] = max(dp[j] + arr[i], dp[i]);
            maxRes = max(maxRes, dp[i]);
    }
    cout << maxRes;
    
}