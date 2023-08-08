#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, s = 0, e = 0, cnt = 0, arr[MAXN];
    cin >> n;
    loop(i, 0, n - 1){
        cin >> arr[i];
    }
    unordered_map<int, int> m;
    while(s < n){
        while(e < n && m[arr[e]] < 1) {
            m[arr[e]]++;
            e++;
        }
        cnt += e - s;
        m[arr[s]]--;
        s++;
    }
    cout << cnt;
}
