#include <iostream>
#define endl '\n'
#define ll long long
#define mod 1000000007

using namespace std;

ll power(ll x, ll n) {
    if (n == 1) return x;
    ll ret = power(x, n / 2);
    ret = (ret * ret) % mod;
    if (n % 2) ret = (ret * x) % mod;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll k, p, n;
    cin >> k >> p >> n;

    cout << (power(p, n * 10) * k) % mod;
}
