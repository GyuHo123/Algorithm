#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001

using namespace std;

int dx[3] = {2, -1, 1};

struct p{
    int x, cnt;
};

int isRange(int x){
    return 0 <= x && x <= 100000;
}

int n, k, arr[MAXN];

int bfs(){
    queue<p> q;
    q.push({n, 0});
    arr[n] = 1;
    while(!q.empty()){
        p t = q.front();
        q.pop();
        loop(i, 0, 2){
            int nx;
            if(i == 0) nx = t.x * dx[i];
            else nx = t.x + dx[i];
            if(nx == k){
                if(i == 0) return t.cnt;
                else return t.cnt + 1;
            }
            if(isRange(nx) && !arr[nx]){
                arr[nx] = 1;
                if(i == 0) q.push({nx, t.cnt});
                else q.push({nx, t.cnt + 1});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(n == k){
        cout << 0;
        exit(0);
    }

    cout << bfs();
}
