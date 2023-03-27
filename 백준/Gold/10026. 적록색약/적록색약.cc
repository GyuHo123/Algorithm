#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 101

using namespace std;

int visited[MAXN][MAXN], cnt, cnt1, n;
char arr[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct p{
    int x, y;
};

bool isRange(int x, int y){
    return 1 <= x && x <= MAXN && 1 <= y && y <= MAXN;
}

void bfs(int x, int y){
    queue<p> q;
    q.push({x, y}); visited[x][y] = 1;
    while(!q.empty()){
        p t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(isRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == arr[x][y]){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main(){
    cin >> n;
    loop(i, 1, n){
        loop(j, 1, n){
            cin >> arr[i][j];
        }
    }
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    loop(i, 1, n){
        loop(j, 1, n){
            if(arr[i][j] == 'G') arr[i][j] = 'R';
        }
    }
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt1++;
            }
        }
    }
    cout << cnt << " " << cnt1;
}