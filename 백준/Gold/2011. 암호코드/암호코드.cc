#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 5001
#define Mod 1000000

using namespace std;

string str;
int temp;
ll dp[MAXN]; //dp[i] = "i번째에서 가질 수 있는 해석의 가짓수"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();

    if (s[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    loop(i, 2, n){
        int one_digit = s[i - 1] - '0';
        int two_digits = (s[i - 2] - '0') * 10 + one_digit;
        if (one_digit == 0 && (two_digits < 10 || two_digits > 26)) {
            cout << 0;
            exit(0);
        }
        if (one_digit >= 1 && one_digit <= 9) {
            dp[i] += dp[i - 1];
            dp[i] %= Mod;
        }
        if (two_digits >= 10 && two_digits <= 26) {
            dp[i] += dp[i - 2];
            dp[i] %= Mod;
        }
    }
    cout << dp[n];
}