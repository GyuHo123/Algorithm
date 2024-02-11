#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

int w, h;
char building[MAXN][MAXN];
int fire[MAXN][MAXN], escape[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void spreadFire() {
    queue<pair<int, int>> q;
    LOOP(i, 0, h) {
        LOOP(j, 0, w) {
            fire[i][j] = -1;
            if (building[i][j] == '*') {
                fire[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        LOOP(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && building[nx][ny] != '#' && fire[nx][ny] == -1) {
                fire[nx][ny] = fire[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int escapeBuilding(int sx, int sy) {
    queue<pair<int, int>> q;
    escape[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == 0 || x == h-1 || y == 0 || y == w-1) return escape[x][y] + 1;
        LOOP(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && building[nx][ny] == '.' && (escape[nx][ny] == -1 || escape[nx][ny] > escape[x][y] + 1) && (fire[nx][ny] == -1 || escape[x][y] + 1 < fire[nx][ny])) {
                escape[nx][ny] = escape[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> w >> h;
        pair<int, int> start;
        LOOP(i, 0, h) {
            cin >> building[i];
            LOOP(j, 0, w) {
                escape[i][j] = -1;
                if (building[i][j] == '@') {
                    start = {i, j};
                    building[i][j] = '.';
                }
            }
        }

        spreadFire();
        int result = escapeBuilding(start.first, start.second);
        if (result == -1) cout << "IMPOSSIBLE" << endl;
        else cout << result << endl;
    }
}
