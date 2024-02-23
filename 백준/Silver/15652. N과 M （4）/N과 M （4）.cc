#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 9

using namespace std;

int res[MAXN];
int m, n;

void dfs(int st, int k){
    if(k == n){
        loop(i, 0, n - 1)
            cout << res[i] << " ";
        cout << endl;
        return;
    }
    else{
        loop(i, st, m){
            res[k] = i;
            dfs(i, k + 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;

    dfs(1, 0);
}