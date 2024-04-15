#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 20001

using namespace std;

int v, e, k, dist[MAXN];

vector<pair<int, int>> v1[MAXN];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    cin >> k;

    loop(i, 1, e){
        int u, v, w;

        cin >> u >> v >> w;

        v1[u].push_back({w, v});
    }

    fill(dist, dist + v + 1, INT_MAX);

    dist[k] = 0;

    pq.push({0, k});

    while(!pq.empty()){
          int curDist = pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();

        if(curDist > dist[curVertex]) continue;

        for(auto &edge : v1[curVertex]){
            int weight = edge.first;
            int nextVertex = edge.second;
            if(dist[nextVertex] > dist[curVertex] + weight){
                dist[nextVertex] = dist[curVertex] + weight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }

    loop(i, 1, v){
        if(dist[i] == INT_MAX) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}