#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, R, ans = 0;
    cin >> N >> R;
    N -= R;

    for (ll i = 1; i * i < N; i++) {
        if (N % i == 0) {
            if (i > R) ans += i;
            if (N / i > R) ans += N / i;
        }
    }

    ll i = (ll)(sqrt(N));
    if (i * i == N && i > R) ans += i;

    cout << ans << endl;
}
