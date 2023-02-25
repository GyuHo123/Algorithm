#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;
int arr[MAXN], n, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    ans = arr[1];
    loop(i, 2, n){
        arr[i] += arr[i - 1];
        ans += arr[i];
    }
    cout << ans;

}
