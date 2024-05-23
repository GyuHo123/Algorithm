#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1001

using namespace std;

int n, arr[MAXN], dp[MAXN], max1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = 1;

    loop(i, 1, n){
        cin >> arr[i];
    }

    loop(i, 1, n){
        loop(j, 1, i - 1){
            if(arr[i] > arr[j]) max1 = max(max1, dp[j]);
        }
        dp[i] = max1 + 1;
        max1 = 0;
    }
    loop(i, 1, n) max1 = max(max1, dp[i]);

    cout << max1;
}