#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s i < n; i++)
#define ll long long
#define MAXN 300001

using namespace std;

ll n, k, arr[MAXN];

ll max(ll a, ll b) {
    return a < b ? b : a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    loop(i, 0, n - 1){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll sum = 0;
    ll l = 0;
    ll r = n - 1;
    loop(i, 1, k){
        if(l <= r) {
            if (i == 1) {
                sum += arr[r];
            }
            else if(!(i % 2) && arr[l] < arr[r]){
                r--;
            }
            else{
                if(arr[r] > arr[l]) sum += arr[r] - arr[l];
                l++;
            }
        }
    }
    cout << sum;
}