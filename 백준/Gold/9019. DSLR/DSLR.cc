#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 10001

using namespace std;

int t, visited[MAXN];

struct p{
    int x;
    string route;
};

string bfs(int start, int end){
    queue<p> q;
    q.push({start, ""});
    memset(visited, 0, sizeof(visited));
    visited[start] = 1;
    while(!q.empty()){
        p t = q.front(); q.pop();
        if(t.x == end){
            return t.route;
        }
        loop(i, 1, 4){
            int nx; string nroute;
            if (i == 1) {
                nx = (t.x * 2) % 10000;
                nroute = t.route + 'D';
            }
            else if (i == 2) {
                nx = (t.x + 9999) % 10000;
                nroute = t.route + 'S';
            }
            else if (i == 3) {
                nx = (t.x % 1000) * 10 + t.x / 1000;
                nroute = t.route + 'L';
            }
            else if (i == 4) {
                nx = (t.x % 10) * 1000 + t.x / 10;
                nroute = t.route + 'R';
            }
            if(!visited[nx]){
                q.push({nx, nroute});
                visited[nx] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        int start, end;
        cin >> start >> end;
        cout << bfs(start, end) << endl;
    }
}