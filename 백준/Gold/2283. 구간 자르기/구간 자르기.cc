#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n ) for(int i = s; i < n; i++)
#define MAXN 2000000
#define MAXK 1000001

using namespace std;

int n, k, arr[MAXN], st, en, sum;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    loop(i, 0, n - 1){
        int t1, t2;
        cin >> t1 >> t2;
        while (t1 + 1 <= t2) {
            arr[t1]++;
            t1++;
        }
    }
    while(st <= en && en < MAXK){
        if(sum == k){
            cout << st << " " << en; exit(0);
        }
        if(sum < k) sum += arr[en++];
        else {
            sum -= arr[st];
            st++;
        }
    }
    cout << 0 << " " << 0;
}