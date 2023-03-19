#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

char arr[13][7];
int visited[13][7], cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct p{
    int x, y;
};

bool isRange(int x, int y){
    return (12 >= x && x >= 1) && (y <= 6 && y >= 1);
}

bool bfs(int xx, int yy){
    memset(visited, 0, sizeof(visited));
    queue<p> q;
    stack<p> stk;
    q.push({xx, yy}); stk.push({xx, yy}); visited[xx][yy] = 1;
    while(!q.empty()){
        p t = q.front(); q.pop();

        LOOP(i, 0, 4){
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(isRange(nx, ny) && arr[nx][ny] == arr[xx][yy] && !visited[nx][ny]){
                q.push({nx, ny}); stk.push({nx, ny}); visited[nx][ny] = 1;
            }
        }
    }
    if(stk.size() >= 4){
        while(!stk.empty()){
            arr[stk.top().x][stk.top().y] = '.';
            stk.pop();
        }
        return 1;
    }
    return 0;
}

void down(){
    for(int i = 12; i > 0; i--){
        for(int j = 6; j > 0; j--){
            if(arr[i][j] == '.'){
                int changePos = i;
                while(changePos > 1 && arr[changePos][j] == '.'){
                    changePos--;
                }
                swap(arr[changePos][j], arr[i][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    loop(i, 1, 12){
        loop(j, 1, 6){
            cin >> arr[i][j];
        }
    }
    while(true) {
        bool isCombo = 0;
        loop(i, 1, 12) {
            loop(j, 1, 6) {
                if (arr[i][j] != '.'){
                    if (bfs(i, j)) {
                        isCombo = true;
                    }
                }
            }
        }
        if(isCombo){
            down();
            cnt++;
            continue;
        }
        break;
    }
    cout << cnt;
}