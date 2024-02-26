#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(long long i = s; i <= n; i++)
#define LOOP(i, s, n) for(long long i = s; i < n; i++)

using namespace std;

long long a, b;

unordered_map<long long, bool> visited;

struct p{
    long long x, cnt;
};

bool isRange(long long x){
    return 1 <= x && x <= 1e9; 
}

long long bfs(){
    queue<p> q;
    q.push({a, 0});
    visited[a] = 1;
    while(!q.empty()){
        p t = q.front();
        q.pop();
        loop(i, 0, 1){
            long long nx;
            if(i == 0) nx = t.x * 10 + 1;
            else nx = t.x * 2;
            if(isRange(nx) && !visited[nx]){
                if(nx == b){
                    return t.cnt + 2;
                }
                else{
                    visited[nx] = 1;
                    q.push({nx, t.cnt + 1});
                }
            }    
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    cout << bfs();
}