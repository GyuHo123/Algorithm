#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1000001

using namespace std;

int f, s, g;
int dy[2], visited[MAXN];

struct p{
    int y, cnt;
};

int isRange(int y){
    return 1 <= y && y <= f;
}

int bfs(){
    if(s == g) return 0;
    queue<p> q;
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty()){
        p t = q.front();
        q.pop();
        loop(i, 0, 1){
            int ny = t.y + dy[i];
            if(isRange(ny) && !visited[ny]){
                if(ny == g) return t.cnt + 1;
                visited[ny] = 1;
                q.push({ny, t.cnt + 1});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> dy[0] >> dy[1];
    dy[1] *= -1;
    int res = bfs();
    if(res == -1) cout << "use the stairs";
    else cout << res;
}