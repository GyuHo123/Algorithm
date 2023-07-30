#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 500001
using namespace std;

int arr[MAXN], temp, n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    loop(i, 1, n){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    cin >> m;
    loop(i, 1, m){
        cin >> temp;
        if(upper_bound(arr + 1, arr + n + 1, temp) - lower_bound(arr + 1, arr + n + 1, temp)) cout << 1 << " ";
        else cout << 0 << " ";
    }
}