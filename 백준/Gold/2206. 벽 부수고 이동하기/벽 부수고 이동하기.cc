#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 1001
using namespace std;

int n, m;
int arr[MAXN][MAXN];
bool visited[MAXN][MAXN][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct p {
    int x, y, dist, wall;
};

int bfs() {
    queue<p> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        p t = q.front();
        q.pop();

        if (t.x == n - 1 && t.y == m - 1) return t.dist;

        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (arr[nx][ny] == 1 && t.wall == 0) {
                visited[nx][ny][1] = true;
                q.push({nx, ny, t.dist + 1, 1});
            }
            else if (arr[nx][ny] == 0 && !visited[nx][ny][t.wall]) {
                visited[nx][ny][t.wall] = true;
                q.push({nx, ny, t.dist + 1, t.wall});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << bfs() << endl;
}
