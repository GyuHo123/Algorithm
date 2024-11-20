#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 2001

using namespace std;

int n, m, flag, visited[MAXN];

vector<int> candirectgo[MAXN];

void dfs(int now, int depth){
    if(flag) return;
    if(depth == 4){
        flag = 1;
        return;
    }
    visited[now] = 1;
    for(auto t : candirectgo[now]){
        if(!visited[t]) dfs(t, depth + 1);
    }
    visited[now] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, m){
        int a, b;
        cin >> a >> b;

        candirectgo[a].push_back(b);
        candirectgo[b].push_back(a);
    }

    loop(i, 0, n - 1){
        memset(visited, 0, sizeof(visited));
        dfs(i, 0);
    }

    if(flag) cout << 1;
    else cout << 0;
}