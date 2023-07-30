#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1000001

using namespace std;


int m, n;
ll snack[MAXN];

bool snack_possible(ll length) {
    int count = 0;

    loop(i, 0, n) {
        count += snack[i] / length;
    }

    return (count >= m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    ll max_length = 0;

    loop(i, 0, n) {
        cin >> snack[i];
        max_length = max(max_length, snack[i]);
    }

    ll low = 1, high = max_length, ans = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (snack_possible(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
