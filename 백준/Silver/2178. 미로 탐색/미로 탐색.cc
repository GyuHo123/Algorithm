//BOJ - 2178

#include<bits/stdc++.h>
#define MAXN 101

using namespace std;

struct p{
    int x, y, depth;
};

int arr[MAXN][MAXN];
int visited[MAXN][MAXN];

int m, n;

int isRange(int x, int y){;
    return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs(){
    queue<p> q;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    q.push({0, 0, 0}); visited[0][0] = 1;

    while(!q.empty()){
        p t = q.front(); q.pop();
        if(t.x == n - 1 && t.y == m - 1) return t.depth + 1;
        for(int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(isRange(nx, ny) && arr[nx][ny] && visited[nx][ny] == 0){
                q.push({nx, ny, t.depth + 1}); visited[nx][ny] = 1;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string ss; cin >> ss;
        for(int j = 0; j < m; j++) arr[i][j] = ss[j] - '0';
    }
    cout << bfs();
}