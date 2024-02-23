#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <=n; i++)
#define MAXN 1000001
using namespace std;

int dp[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    
    loop(i, 3, n){
        dp[i] = (dp[i - 2] + dp[i - 1])%15746;
    }
    
    cout << dp[n] % 15746 << endl;    
    
}