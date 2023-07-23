#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 10001

using namespace std;

ll l, k, c, cut[MAXN], len[MAXN];

ll solve(ll m){
    ll chance = c, t = 0;
    for(ll i = k; i >= 0; i--){
        if(len[i] > m) return -1;
        t += len[i];
        if(t > m){
            chance--;
            t = len[i];
        }
        if(!chance){
            if(cut[i] > m) return -1;
            return cut[i];
        }
    }
    return cut[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> k >> c;
    if(c > k) c = k;

    loop(i, 0, k - 1) cin >> cut[i]; cut[k] = l;
    sort(cut, cut + k);
    loop(i, 1, k) len[i] = cut[i] - cut[i - 1]; len[0] = cut[0];

    ll s = 1, e = l, a, b;
    while(s <= e){
        ll m = (s + e) >> 1;
        ll k = solve(m);
        if(k >= 0) a = m, b = k, e = m - 1;
        else s = m + 1;
    }
    cout << a << ' ' << b << endl;
}