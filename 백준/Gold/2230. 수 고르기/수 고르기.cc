#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, m, s, e, arr[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int ans = 2000000000;

    LOOP(i, 0, n){
        cin >> arr[i];
    }

    sort(arr, arr + n);
    while(s <= e && e < n){
        int temp = arr[e] - arr[s];
        if(temp < m) e++;
        else{
            ans = min(ans, temp);
            s++;
        }
    }
    cout << ans << endl;
}