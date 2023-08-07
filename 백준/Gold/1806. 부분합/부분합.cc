#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

int n, s, start, last, ans = 100000000, arr[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    LOOP(i, 0, n){
        cin >> arr[i];
    }
    int temp = 0;
    while(start <= last){
        if(temp >= s){
            ans = min(ans, last - start);
            temp -= arr[start++];
        }
        else if(last == n) break;
        else temp += arr[last++];
    }
    if(ans == 100000000) cout << 0 << endl;
    else cout << ans << endl;
}