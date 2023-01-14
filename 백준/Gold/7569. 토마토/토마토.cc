#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 101

using namespace std;

struct p{
    int x;
    int y;
    int z;
    int depth;
};

int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};
int m, n, h, arr[MAXN][MAXN][MAXN];

int isRange(int x, int y, int z){
    return 1 <= x && x <= m && 1 <= y && y <= n && 1 <= z && z <= h;
}

int bfs() {
    int max_depth = 0;
    queue<p> q;
    for(int zz = 1; zz <= h; zz++){
        for(int yy = 1; yy <= n; yy++){
            for(int xx = 1; xx <= m; xx++){
                if(arr[zz][yy][xx] == 1){
                    q.push({xx, yy, zz, 0});
                }
            }
        }
    }
    while(!q.empty()){
        p t = q.front(); q.pop();
        max_depth = max(max_depth, t.depth);
        for(int i = 0; i < 6; i++) {
            int nx = t.x + dx[i]; int ny = t.y + dy[i]; int nz = t.z + dz[i];
            if(isRange(nx, ny, nz) && arr[nz][ny][nx] == 0){
                q.push({nx, ny, nz, t.depth + 1}); arr[nz][ny][nx] = 1;
            }
        }
    }
    for(int z = 1; z <= h; z++)
        for(int y = 1; y <= n; y++)
            for(int x = 1; x <= m; x++)
                if(arr[z][y][x] == 0) return -1;
    return max_depth;
}

int main() {
    bool b = false, b1 = false;
    cin >> m >> n >> h;
    for(int z = 1; z <= h; z++){
        for(int y = 1; y <= n; y++){
            for(int x = 1; x <= m; x++){
                cin >> arr[z][y][x];
                if(arr[z][y][x] == 0) b = true;
                if(arr[z][y][x] == 1) b1 = true;
            }
        }
    }
    if(!b && b1) {
        cout << 0; exit(0);
    }
    cout << bfs() << endl;
}