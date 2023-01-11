// BOJ - 7576 토마토

#include <bits/stdc++.h>
#define MAXN 1000 + 1

using namespace std;

struct p {
    int x, y, depth;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m, arr[MAXN][MAXN], visited[MAXN][MAXN];
int isRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
int bfs() {
    int max_depth = 0;
    queue<p> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(arr[i][j] == 1) {
                q.push({i, j, 0});
            }
    while(!q.empty()) {
        p t = q.front(); q.pop();
        max_depth = max(max_depth, t.depth);
        for(int i = 0; i <= 3; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(isRange(nx, ny) && arr[nx][ny] == 0) {
                q.push({nx, ny, t.depth + 1}); arr[nx][ny] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(arr[i][j] == 0) return -1;
    return max_depth;
}
int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    cout << bfs() << '\n';
}