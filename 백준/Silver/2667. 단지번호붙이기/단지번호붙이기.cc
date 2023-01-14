#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 26

using namespace std;

struct p{
    int x, y;
};

int arr[MAXN][MAXN], cnt, n;

vector<int> v;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int isRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void bfs(int xx, int yy){
    cnt = 0;
    queue<p> q;
    q.push({xx, yy}); arr[xx][yy] = 0; cnt++;
    while(!q.empty()){
        p t = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(isRange(nx, ny) && arr[nx][ny]){
                q.push({nx, ny}); cnt++; arr[nx][ny] = 0;
            }
        }
    }
    v.push_back(cnt);
}

int main(){
    string ss;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ss;
        for(int j = 1; j <= n; j++){
            arr[i][j] = ss[j - 1] - '0';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == 1){
                bfs(i, j);
            }
        }
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}