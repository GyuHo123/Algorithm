#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


int visited[100001], res, endNode;
vector<int> v;

struct p{
    int x, preRes;
};

vector<p> point[100001];

int dfs(int start, int weight){
    if(visited[start]) return 1;
    visited[start] = 1;
    if(res < weight){
        res = weight;
        endNode = start;
    }
    for(int i = 0; i < point[start].size(); i++){
        dfs(point[start][i].x, weight + point[start][i].preRes);
    }
    return 1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int from, to, weight;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> from;
        while (true)
        {
            cin >> to;
            if (to == -1)
                break;
            cin >> weight;
            point[from].push_back({to, weight});
            point[to].push_back({from, weight});
        }
    }

    dfs(2, 0);
    res = 0;
    memset(visited, 0, sizeof(visited));
    dfs(endNode, 0);
    cout << res << endl;
}