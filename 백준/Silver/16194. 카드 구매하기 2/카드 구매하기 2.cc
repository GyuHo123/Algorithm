#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int dp[10001];
int weight[10001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> weight[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i] = weight[i];
        for(int j = 1; j <= i; j++)
        dp[i] = min(dp[i], dp[i - j] + weight[j]);
    }
    cout << dp[n];
}
