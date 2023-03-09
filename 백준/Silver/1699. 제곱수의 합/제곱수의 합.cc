#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, dp[MAXN];// dp[i] = i를 제곱수들의 합으로 표현할 때 그 항의 최소개수 // dp[j

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    dp[1] = 1;
    loop(i, 1, n)
        dp[i] = i;
    loop(i, 1, n)
        for(int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    cout << dp[n];
}
