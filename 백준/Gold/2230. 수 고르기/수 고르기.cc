#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, m, arr[MAXN], en, ans = INT_MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    LOOP(i, 0, n){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    LOOP(i, 0, n){
        while(en < n && arr[en] - arr[i] < m) en++;
        if(en == n) break;
        ans = min(ans, arr[en] - arr[i]);
    }
    cout << ans;
}