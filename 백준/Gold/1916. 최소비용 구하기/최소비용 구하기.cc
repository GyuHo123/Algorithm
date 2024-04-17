#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1001

using namespace std;

int n, m, st, en, dist[MAXN];
vector<pair<int, int>> v1[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        v1[u].push_back({w, v});
    }
    cin >> st >> en;

    fill(dist, dist + 1 + n, INT_MAX);

    dist[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        if(dist[t.second] < t.first) continue;
        for(auto nxt : v1[t.second]){
            if(dist[nxt.second] <= dist[t.second] + nxt.first) continue;
            dist[nxt.second] = dist[t.second] + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
        }
    }
    cout << dist[en];
}