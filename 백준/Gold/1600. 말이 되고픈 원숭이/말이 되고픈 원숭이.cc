    #include <bits/stdc++.h>
    #define endl '\n'
    #define loop(i, s, n) for(int i = s; i <= n; i++)
    #define MAXN 201

    using namespace std;

    int w, h, k;
    int arr[MAXN][MAXN];
    int visited[MAXN][MAXN][31];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int horseX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int horseY[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    struct p{
        int x, y, cnt, horse;
    };

    int isRange(int x, int y){
        return 1 <= x && x <= h && 1 <= y && y <= w;
    }

    int bfs(){
        queue<p> q;
        q.push({1, 1, 0, 0});
        visited[1][1][0] = 1;
        while(!q.empty()){
            p t = q.front();
            q.pop();
            loop(i, 0, 3){
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];
                if(t.x == h && t.y == w) return t.cnt;
                if(isRange(nx, ny) && !arr[nx][ny] && !visited[nx][ny][t.horse]){
                    q.push({nx, ny, t.cnt + 1, t.horse});
                    visited[nx][ny][t.horse] = 1;
                }
            }
            if(t.horse < k){
                loop(i, 0, 7){
                    int nx = t.x + horseX[i];
                    int ny = t.y + horseY[i];
                    if(isRange(nx, ny) && !arr[nx][ny] && !visited[nx][ny][t.horse + 1]){
                        visited[nx][ny][t.horse + 1] = 1;
                        q.push({nx, ny, t.cnt + 1, t.horse + 1});
                    }
                }
            }
        }
        return -1;
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> k >> w >> h;

        loop(i, 1, h){
            loop(j, 1, w){
                cin >> arr[i][j];
            }
        }

        if(w == 1 && h == 1){
            if(!arr[w][h]) cout << 0;
            else cout << -1;
            exit(0);
        }

        cout << bfs();
    }