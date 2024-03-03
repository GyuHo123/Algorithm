#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 101

using namespace std;

int dx[4] = {0, 0, 1, - 1};
int dy[4] = {1, -1, 0, 0};

int n, m;

int arr[MAXN][MAXN];
int visited[MAXN][MAXN];
int can[MAXN][MAXN];

struct p{
    int a, b;
    bool operator<(const p& other) const {
        return a == other.a ? b < other.b : a < other.a;
    }
};

map<p, vector<p>> m1;

int isRange(int a, int b){
    return 1 <= a && a <= n && 1 <= b && b <= n;
}

int bfs(){
    queue<p> q;
    arr[1][1] = 1;
    visited[1][1] = 1;
    can[1][1] = 1;
    int cnt = 1;
    q.push({1, 1});
    while(!q.empty()){
        p t1 = q.front();
        q.pop();
        for(auto t: m1[{t1.a, t1.b}]){
            if(!arr[t.a][t.b]) {
                arr[t.a][t.b] = 1;
                cnt++;
            }
        }
        loop(i, 0, 3){
            int nx = t1.a + dx[i], ny = t1.b + dy[i];
            if(isRange(nx, ny)) can[nx][ny] = 1;
        }
        loop(i, 1, n){
            loop(j, 1, n){
                if(arr[i][j] && can[i][j] && !visited[i][j]){
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, m){
        p t1, t2;
        cin >> t1.a >> t1.b >> t2.a >> t2.b;
        m1[{t1.a, t1.b}].push_back(t2);
    }

    cout << bfs() << endl;
}
