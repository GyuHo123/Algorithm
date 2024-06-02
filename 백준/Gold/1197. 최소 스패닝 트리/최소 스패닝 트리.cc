#include <bits/stdc++.h>
#define MAXN 10001
#define endl '\n'

using namespace std;

vector<pair<int, int>> adj[MAXN];
bool visited[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    int total_weight = 0;
    int edges_used = 0;

    while (!pq.empty() && edges_used < v) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        total_weight += cost;
        edges_used++;

        for (auto &edge : adj[node]) {
            int next_cost = edge.first;
            int next_node = edge.second;
            if (!visited[next_node]) {
                pq.push({next_cost, next_node});
            }
        }
    }

    cout << total_weight << endl;
    return 0;
}
