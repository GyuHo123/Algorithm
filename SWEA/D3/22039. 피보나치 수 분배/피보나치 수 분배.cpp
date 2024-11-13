#include <iostream>
#define loop(i, s, n) for (int i = s; i <= n; i++)
#define endl '\n'
#define MAXN 101

using namespace std;

int t, p, dp[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    loop(i, 4, 100) {
        dp[i] = dp[i - 3];
    }

    loop(i, 1, t) {
        int n;
        cin >> n;
        if(!dp[n]) {
            cout << "impossible" << endl;
            continue;
        }
        if(n % 3 != 0) cout << "BA";
        if(n < 3) {
            cout << endl;
            continue;
        }
        loop(i, 1, n / 3) {
            cout << "BBA";
        }
        cout << endl;
    }
}