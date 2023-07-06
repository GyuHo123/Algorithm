#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN

using namespace std;

// dp[i] = "i원을 만드는데 필요한 동전의 개수"
ll dp[101];
ll n, res;
int t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    loop(i, 1, 100) { // 전처리
        dp[i] = dp[i - 1] + 1;
        if(i >= 10) dp[i] = min(dp[i], dp[i - 10] + 1);
        if(i >= 25) dp[i] = min(dp[i], dp[i - 25] + 1);
    }
    
    cin >> t;

    while(t--) {
        cin >> n;
        while(n) {
            res += dp[n % 100]; //1, 10, 25의 100의 배수로 진행되는 규칙
            n /= 100;
        }
        cout << res << endl;
        res = 0;
    }
}