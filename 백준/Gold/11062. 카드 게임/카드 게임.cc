#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1001

using namespace std;

int t, n, arr[MAXN];
int dp[MAXN][MAXN];

int turn(int left, int right) {
    if (left > right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int left_card = arr[left] + min(turn(left + 2, right), turn(left + 1, right - 1));
    int right_card = arr[right] + min(turn(left + 1, right - 1), turn(left, right - 2));

    return dp[left][right] = max(left_card, right_card);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;

        loop(i, 0, n - 1)
            cin >> arr[i];

        memset(dp, -1, sizeof(dp));

        cout << turn(0, n - 1) << endl;
    }
}
