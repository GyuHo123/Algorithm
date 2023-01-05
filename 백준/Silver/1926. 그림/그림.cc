#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 501

using namespace std;

vector<int> v;

int n, m, cnt, cnt1, arr[MAXN][MAXN], visited[MAXN][MAXN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int isRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
void bfs(int x, int y) {
    cnt1 = 1;
    queue<pair<int, int>> q; q.push({x, y}); visited[x][y] = 1;
    while(!q.empty()) {
        pair<int, int> pii = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = pii.first + dx[i], ny = pii.second + dy[i];
            if(isRange(nx, ny) && arr[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = 1; q.push({nx, ny});
                cnt1++;
            }
        }
    }
    v.push_back(cnt1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (arr[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
    sort(v.begin(), v.end());
    cout << cnt << endl;
    if(!v.empty()) cout << v.back();
    else cout << 0;
}