#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1001
using namespace std;

int N, M, V;
int adj[MAXN][MAXN];
int visited[MAXN];
queue<int> Q;

void dfs(int node) {
    visited[node] = true;
    cout << node << ' ';
    loop(i, 1, N) {
        if(adj[node][i] && !visited[i]) dfs(i);
    }
}

void bfs(int start) {
    visited[start] = true;
    Q.push(start);
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        cout << x << ' ';
        loop(i, 1, N) {
            if(adj[x][i] && !visited[i]) {
                Q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    loop(i, 1, M) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }

    dfs(V);
    cout << endl;
    memset(visited, false, sizeof(visited));
    bfs(V);
    cout << endl;

    return 0;
}
