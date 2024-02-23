#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 9

using namespace std;

int res[MAXN];
int visited[MAXN];
int m, n;

void dfs(int k){
    if(k == n){
        loop(i, 0, n - 1)
            cout << res[i] << " ";
        cout << endl;
        return;
    }
    loop(i, 1, m){
        if(!visited[i]){
            visited[i] = 1;
            res[k] = i;
            dfs(k + 1);
            visited[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;

    dfs(0);
}