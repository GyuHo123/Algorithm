#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 201

using namespace std;

int t, lev[MAXN], cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    loop(i, 1, t){
        cin >> lev[i];
    }
    for(int i = t; i >= 1; i--){
        while(lev[i] <= lev[i - 1]){
            lev[i - 1]--;
            cnt++;
        }
    }
    cout << cnt;
}