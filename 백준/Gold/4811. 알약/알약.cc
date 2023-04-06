#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int n;
unsigned long long dp[31]; //dp[i] == "i개의 약이 들어있는 병에 대해 생성되는 서로 다른 문자열의 개수"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dp[0] = dp[1] = 1;
    loop(i, 2, 30) {
        dp[i] = 0;
        LOOP(j, 0, i) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    while (1) {
        cin >> n;
        if (!n) break;
        cout << dp[n] << endl;
    }
}