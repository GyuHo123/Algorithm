#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

ll pow_mod(ll a, ll b, ll c) {
    if (b == 0) return 1;
    ll val = pow_mod(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 1) val = val * a % c;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow_mod(a, b, c) << endl;
}
