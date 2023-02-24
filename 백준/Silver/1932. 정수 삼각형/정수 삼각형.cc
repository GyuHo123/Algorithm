#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int dp[600][600];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i = n; i > 1; i--){
        for(int j = 1; j <= i; j++){
            dp[i - 1][j] += max(dp[i][j], dp[i][j+1]);
        }
    }

    cout << dp[1][1];

}
