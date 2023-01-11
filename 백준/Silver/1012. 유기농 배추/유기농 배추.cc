#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 51

using namespace std;

struct p{
    int x, y;
};

int m, n, cnt, arr[MAXN][MAXN], visited[MAXN][MAXN];

bool isRange(int x, int y){
    return 0 <= x && x < m && 0 <= y && y < n;
};

void bfs(int x, int y){
    queue<p> q;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    q.push({x, y}); visited[x][y] = 1;
    while(!q.empty()){
        p t = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = t.x + dx[i]; int ny = t.y + dy[i];
            if(isRange(nx, ny) && arr[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = 1; q.push({nx, ny});
            }
        }
    }
}
void arrIni(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            arr[i][j] = 0; visited[i][j] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, x, y, k;

    cin >> t;
    
    int copyt = t;

    while(t--) {
        if(copyt > t) arrIni();
        
        cnt = 0;

        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
        cout << cnt << endl;
    }
}