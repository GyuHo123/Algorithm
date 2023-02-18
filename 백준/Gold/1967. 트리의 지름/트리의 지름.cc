#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


int visited[10001], res, endNode;

struct p{
    int x, preRes;
};

vector<p> point[10001];

int dfs(int start, int std){
    if(visited[start]) return 1;
    visited[start] = 1;
    if(res < std){
        res = std;
        endNode = start;
    }
    for(int i = 0; i < point[start].size(); i++){
        dfs(point[start][i].x, std + point[start][i].preRes);
    }
    return 1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        point[a].push_back({b, c});
        point[b].push_back({a, c});
    }

    dfs(1, 0);

    res = 0;

    memset(visited, 0, sizeof(visited));
    dfs(endNode, 0);
    cout << res;
}
