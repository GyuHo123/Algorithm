#include<bits/stdc++.h>
#define endl '\n'

//LIS = if(arr[i] < arr[j])max(dp[j] + 1, dp[i])
//LDS = if(arr[i] > arr[j])max(dp[j] + 1, dp[i])
//fin = LIS[i]+LDS[i]

using namespace std;

int dp[1001], dp2[1001], arr[1001], arr2[1001], n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr2[n + 1 - i] = arr[i];
        dp[i] = dp2[i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if(arr[j] < arr[i]) dp[i] = max(dp[j] + 1, dp[i]);
            if(arr2[j] < arr2[i]) dp2[i] = max(dp2[j] + 1, dp2[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(dp[i] + dp2[n + 1 - i] - 1, ans);
    }

    cout << ans;
}