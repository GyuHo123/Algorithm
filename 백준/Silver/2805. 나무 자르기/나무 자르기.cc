#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n ; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long

using namespace std;

vector<ll> v1;
ll n, m, h, res, temp, max1;

ll count(int m1){
    ll ret = 0;
    for(ll t : v1){
        if(t > m1){
            ret += (t - m1);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n){
        cin >> temp;
        max1 = max(temp, max1);
        v1.push_back(temp);
    }
    int s = 0, e = max1;
    while(s <= e){
        ll cent = (s + e) / 2;
        if(count(cent) >= m){
            res = cent;
            s = cent + 1;
        }
        else e = cent - 1;
    }
    cout << res;
}