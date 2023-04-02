#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 10001

using namespace std;

int arr[MAXN], len[MAXN], n, k, res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;

    loop(i, 0, n - 1){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    loop(i, 0, n - 2){
        len[i] = arr[i + 1] - arr[i];
    }
    sort(len, len + n - 1);
    loop(i, 0, n - k - 1){
        res += len[i];
    }
    cout << res;
}