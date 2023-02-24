#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

long long dp[100001][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    int mod = 1000000009;

    cin >> n;

    dp[1][0] = dp[2][0] = 1;
    dp[3][0] = 3;

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i < 100001; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod ;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod ;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod ;
        dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % mod;
    }

    while(n--){
        int temp;
        cin >> temp;
        cout << dp[temp][0] << endl;
    }

}