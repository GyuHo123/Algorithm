#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> nxt[51];
int deleted[51], n, cnt=0;

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    deleted[cur] = 1;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int nx : nxt[t]) {
            if (!deleted[nx]) {
                deleted[nx] = 1;
                q.push(nx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int del;

    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp == -1) continue;
        nxt[temp].push_back(i);
    }

    cin >> del;
    bfs(del);
    for(int i = 0; i < n; i++){
        if(nxt[i].empty() && !deleted[i]) cnt++;
        else if(nxt[i].size() == 1 && deleted[nxt[i][0]] && !deleted[i]) cnt++;
        else if(n == 1 && deleted[0]) cnt = 0;
    }
    cout << cnt;
}