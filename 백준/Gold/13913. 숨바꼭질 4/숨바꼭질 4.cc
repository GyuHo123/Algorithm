#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001

using namespace std;

int n, k;
vector<int> visited(MAXN), prevPos(MAXN);

int isRange(int x){
    return 0 <= x && x < MAXN;
}

void bfs(){
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()){
        int t1 = q.front();
        q.pop();
        int dx[] = {t1 * 2, t1 - 1, t1 + 1};
        loop(i, 0, 2){
            int nx = dx[i];
            if(isRange(nx) && !visited[nx]){
                visited[nx] = visited[t1] + 1; 
                prevPos[nx] = t1;
                q.push(nx);
            }
        }
    }
    cout << visited[k] - 1 << endl;
    visited.clear();
    vector<int>().swap(visited);
    vector<int> path;

    for(int at = k; at != n; at = prevPos[at]) path.push_back(at);
    vector<int>().swap(prevPos);
    path.push_back(n);

    reverse(path.begin(), path.end());
    for(auto t : path){
        cout << t << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    bfs();

}