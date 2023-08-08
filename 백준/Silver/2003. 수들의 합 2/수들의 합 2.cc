#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 10001

using namespace std;

int arr[MAXN], n, m, s, e, result = 300000000, cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    LOOP(i, 0, n) cin >> arr[i];

    int tsum = arr[0];

    while(e < n){
        if(tsum > m) tsum -= arr[s++];
        else if(tsum < m) tsum += arr[++e];
        if(tsum == m){
            cnt++;
            tsum -= arr[s++];
        }
    }
    cout << cnt;
}