#include <bits/stdc++.h>
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 101
#define endl '\n'

using namespace std;

int n;
int num[MAXN];
ll dp[MAXN][21]; //dp[i][j] = “i번째 수에서 j 값을 가지는 경우의 수”

int main(){
    cin >> n;
    loop(i, 1, n) cin >> num[i];

    dp[1][num[1]] = 1;

    loop(i, 2, n-1){
        loop(j, 0, 20){
            if (dp[i-1][j] > 0) {
                int plus_val = j + num[i];
                int minus_val = j - num[i];
                if (plus_val <= 20) dp[i][plus_val] += dp[i-1][j];
                if (minus_val >= 0) dp[i][minus_val] += dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][num[n]] << "\n";
}