#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 501

using namespace std;

struct p{
    int x, y, c;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int arr[MAXN][MAXN];
int visited[MAXN][MAXN];

bool isRange(int x,int y){
    return (x >= 0 && x <= 500 && y >= 0 && y <=500);
}
void color(int clr, int x0, int y0, int x1, int y1) {
    int xmin = min(x0, x1), xmax = max(x0, x1);
    int ymin = min(y0, y1), ymax = max(y0, y1);

    loop(i, xmin, xmax) loop(j, ymin, ymax) arr[i][j] = clr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, y1, x2, y2;
    memset(visited, -1, sizeof visited);
    cin >> n;
    loop(i, 0, n - 1){
        cin >> x1 >> y1 >> x2 >> y2;
        color(1, x1, y1, x2, y2);
    }
    cin >> m;
    loop(i, 0, m - 1){
        cin >> x1 >> y1 >> x2 >> y2;
        color(2, x1, y1, x2, y2);
    }
    queue<p> q;
    q.push({0,0,0});
    visited[0][0] = 0;
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, c = q.front().c;
        q.pop();
        loop(i, 0, 3){
            int nx = x + dx[i], ny = y + dy[i];
            if(isRange(nx, ny) && arr[nx][ny] < 2){
                if(visited[nx][ny] < 0 || visited[nx][ny] > c + arr[nx][ny]){
                    visited[nx][ny] = c + arr[nx][ny];
                    q.push({nx, ny, visited[nx][ny]});
                }
            }
        }
    }
    cout << visited[500][500] << endl;
}
