#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 101

using namespace std;

vector<pair<int, int>> arr[MAXN];
int d[MAXN], n, m, r, ans;
int items[MAXN];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    loop(i, 1, n){
        cin >> items[i];
    }

    loop(i, 1, r){
        int t1, t2, cost;
        cin >> t1 >> t2 >> cost;
        arr[t1].push_back({cost, t2});
        arr[t2].push_back({cost, t1});
    }
    loop(i, 1, n){
        fill(d, d + n + 1, INT_MAX);
        int st = i;
        d[i] = 0;
        pq.push({d[st], st});
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(d[cur.second] != cur.first) continue;
            for(auto nxt: arr[cur.second]){
                if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
                d[nxt.second] = d[cur.second] + nxt.first;
                pq.push({d[nxt.second], nxt.second});
            }
        }
        int tans = 0;
        loop(i, 1, n){
            if(d[i] <= m) tans += items[i];
        }
        if(ans < tans) ans = tans;
    }
    cout << ans;
}