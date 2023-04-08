#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[101][101], visited[101][101];

int bfs(int x, int y) {
    int area = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && !arr[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = y1; x < y2; x++) {
            for (int y = x1; y < x2; y++) {
                arr[x][y] = 1;
            }
        }
    }

    vector<int> areas;
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            if (!visited[x][y] && !arr[x][y]) {
                areas.push_back(bfs(x, y));
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << areas.size() << endl;
    for (int i = 0; i < areas.size(); i++) {
        cout << areas[i] << " ";
    }
}
