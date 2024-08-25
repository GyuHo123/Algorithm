#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1001

using namespace std;

int n, arr[MAXN], dp[MAXN]; //dp[n] = "n개의 카드를 갖기 위해 지불해야 하는 최대 금액"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> arr[i];
    }

    loop(i, 1, n){
        loop(j, 1, i){
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }

    cout << dp[n];
}