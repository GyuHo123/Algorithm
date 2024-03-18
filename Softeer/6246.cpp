#include <iostream>
#include <vector>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 5
using namespace std;

int arr[MAXN][MAXN], visited[MAXN][MAXN], ans;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, m;

struct p{
    int x, y;
};

vector<p> checkpoints;

int isRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n; 
}

void dfs(int x, int y, int cnt){
    if(cnt == m){
        ans++;
        return;
    }
    p nextCheckpoint = checkpoints[cnt];
    loop(i, 0, 3){
        int nx = x + dx[i], ny = y + dy[i];
        if(isRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 1){
            visited[nx][ny] = 1;
            if(nx == nextCheckpoint.x && ny == nextCheckpoint.y){
                dfs(nx, ny, cnt + 1);
            } else {
                dfs(nx, ny, cnt);
            }
            visited[nx][ny] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n){
        loop(j, 1, n){
            cin >> arr[i][j];
        }
    }

    loop(i, 0, m - 1){
        int x, y;
        cin >> y >> x;
        checkpoints.push_back({y, x});
    }

    p start = checkpoints[0];
    visited[start.x][start.y] = 1;
    dfs(start.x, start.y, 1);
    cout << ans;
}
