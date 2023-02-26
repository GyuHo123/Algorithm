#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001
using namespace std;

int n, t, arr[MAXN], res[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    loop(i, 1, n){
        cin >> arr[i];
        res[i] += arr[i] + res[i - 1];
    }

    while(t--){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cout << res[temp2] - res[temp1 - 1] << endl;
    }
}