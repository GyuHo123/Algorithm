#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 9

using namespace std;

struct p{
    int x, y;
};

int arr[MAXN][MAXN], copyarr[MAXN][MAXN], n, m, res = INT_MIN;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
vector<p> virus;
int isRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs(){
    int virusarr[MAXN][MAXN];
    loop(i, 1, n){
        loop(j, 1, m){
            virusarr[i][j] = copyarr[i][j];
        }
    }
    queue<p> q;
    int zerocnt = 0;
    for(auto t: virus){
        q.push(t);
    }
    while(!q.empty()){
        p t1 = q.front();
        q.pop();
        loop(i, 0, 3){
            int nx = t1.x + dx[i], ny = t1.y + dy[i];
            if(isRange(nx, ny) && !virusarr[nx][ny]){
                virusarr[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    loop(i, 1, n){
        loop(j, 1, m)
            if(!virusarr[i][j]) zerocnt++;
    }
    res = max(res, zerocnt);
}

void setwall(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    else{
        loop(i, 1, n){
            loop(j, 1, m){
                if(!copyarr[i][j]){
                    copyarr[i][j] = 1;
                    setwall(cnt + 1);
                    copyarr[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n){
        loop(j, 1, m){
            cin >> arr[i][j];
        }
    }
    loop(i, 1, n){
        loop(j, 1, m){
            copyarr[i][j] = arr[i][j];
        }
    }
    loop(i, 1, n){
        loop(j, 1, m){
            if(arr[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }
    setwall(0);
    cout << res;
}