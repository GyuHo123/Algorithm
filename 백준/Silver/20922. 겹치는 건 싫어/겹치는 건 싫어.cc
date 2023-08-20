#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 200001

using namespace std;

int n, k, st, en, ans, arr[MAXN], cnt[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    LOOP(i, 0, n){
        cin >> arr[i];
    }
    while(st <= en && en < n){
        if(cnt[arr[en]] < k){
            cnt[arr[en++]]++;
            ans = max(ans, en - st);
        }
        else if(cnt[arr[en]] == k){
            cnt[arr[st++]]--;
        }
    }
    cout << ans;
}
