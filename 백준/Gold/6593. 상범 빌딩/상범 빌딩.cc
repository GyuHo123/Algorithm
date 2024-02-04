#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 31

using namespace std;

struct p {
    int l, r, c, cnt;
};

int L, R, C;
char building[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
int dl[] = {-1, 1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 0, -1, 1};

bool isInRange(int l, int r, int c) {
    return l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C;
}

int bfs(p start) {
    queue<p> q;
    q.push(start);
    visited[start.l][start.r][start.c] = true;

    while (!q.empty()) {
        p t = q.front(); q.pop();

        if (building[t.l][t.r][t.c] == 'E') return t.cnt;

        for (int i = 0; i < 6; i++) {
            int nl = t.l + dl[i];
            int nr = t.r + dr[i];
            int nc = t.c + dc[i];

            if (isInRange(nl, nr, nc) && !visited[nl][nr][nc] && building[nl][nr][nc] != '#') {
                visited[nl][nr][nc] = true;
                q.push({nl, nr, nc, t.cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        memset(visited, 0, sizeof(visited));

        p start;
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    cin >> building[l][r][c];
                    if (building[l][r][c] == 'S') {
                        start = {l, r, c, 0};
                    }
                }
            }
        }

        int res = bfs(start);
        if (res != -1) cout << "Escaped in " << res << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }
}
