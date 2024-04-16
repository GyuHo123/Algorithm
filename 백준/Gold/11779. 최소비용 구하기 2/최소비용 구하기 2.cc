#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1001

using namespace std;

int n, m, st, en, dist[MAXN], pre[MAXN];
vector<pair<int, int>> v1[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


vector<int> cities;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, m){
        int st, en, cost;

        cin >> st >> en >> cost;

        v1[st].push_back({cost, en});
    }

    cin >> st >> en;

    fill(dist, dist + n + 1, INT_MAX);

    dist[st] = 0;

    pq.push({dist[st], st});

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        if(dist[t.second] < t.first) continue;
        for(auto nxt : v1[t.second]){
            if(dist[nxt.second] <= dist[t.second] + nxt.first) continue;
            dist[nxt.second] = dist[t.second] + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
            pre[nxt.second] = t.second;
        }
    }
    cout << dist[en] << endl;
    int t1 = en;
    while(t1 != st){
        cities.push_back(t1);
        t1 = pre[t1];
    }
    cities.push_back(st);
    cout << cities.size() << endl;
    for(int i = cities.size() - 1; i >= 0; i--){
        cout << cities[i] << " ";
    }
}
