#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 10001

using namespace std;

vector<vector<int>> arr(10001);
vector<int> cntv1(10001);
vector<int> ans;
int visited[MAXN];

int n, m, max1;

struct p{
    int x, y, cnt;
};

int bfs(int num){
    memset(visited, 0, sizeof(visited));
    int depth = 0;
    queue<int> q;
    q.push(num);
    visited[num] = 1;
    while(!q.empty()){
        int t1 = q.front();
        q.pop();
        depth++;        
        for(auto t : arr[t1]){
            if(!visited[t]){
                visited[t] = 1;
                q.push(t);
            }
        }
    }
    cntv1[num] = depth;
    return depth; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, m){
        p t;
        cin >> t.x >> t.y;
        arr[t.y].push_back(t.x);      
    }
    loop(i, 1, n){
        max1 = max(max1, bfs(i));
    }

    loop(i, 1, n){
        if(max1 == cntv1[i]){
            ans.push_back(i);
        }
    }
    for(auto t: ans){
        cout << t << " ";
    }
}