#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

int arr[MAXN][MAXN];
int ghost[MAXN][MAXN];
int human[MAXN][MAXN];

int n, m;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

struct p{
    int x, y;
};

int isRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void ghostMove(){
    queue<p> q;
    loop(i, 1, n){
        loop(j, 1, m){
            if(arr[i][j] == 2){
                ghost[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        p t = q.front();
        q.pop();
        loop(i, 0, 3){
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(isRange(nx, ny) && ghost[nx][ny] == -1){
                ghost[nx][ny] = ghost[t.x][t.y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool humanMove(p h){
    queue<p> q;
    q.push(h);
    human[h.x][h.y] = 0;
    while(!q.empty()){
        p t = q.front();
        q.pop();
        loop(i, 0, 3){
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(isRange(nx, ny) && ghost[nx][ny] > human[t.x][t.y] + 1 && human[nx][ny] == -1 && arr[nx][ny] != 1){
                q.push({nx, ny});
                human[nx][ny] = human[t.x][t.y] + 1;
                if(arr[nx][ny] == 3) return 1;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(ghost, -1, sizeof(ghost));
    memset(human, -1, sizeof(human));
    cin >> n >> m;
    string s;
    p start;
    loop(i, 1, n){
        cin >> s;
        loop(j, 0, s.size() - 1){
            if(s[j] == '.') continue;
            if(s[j] == '#') arr[i][j + 1] = 1;
            else if(s[j] == 'G') arr[i][j + 1] = 2;
            else if(s[j] == 'D') arr[i][j + 1] = 3;
            else arr[i][j + 1] = 4, start = {i, j + 1};
        }
    }
    ghostMove();
    if(!humanMove(start)) cout << "No";
    else cout << "Yes";
}
