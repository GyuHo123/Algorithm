#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, s, st, en, ans = INT_MAX, sum, arr[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    LOOP(i, 0, n){
        cin >> arr[i];
    }
    LOOP(st, 0, n){
        while(en <= n && sum < s) sum += arr[en++];
        if(sum >= s) ans = min(ans, en - st);
        sum -= arr[st];
    }
    if(ans == INT_MAX) cout << 0 << endl;
    else cout << ans << endl;
}