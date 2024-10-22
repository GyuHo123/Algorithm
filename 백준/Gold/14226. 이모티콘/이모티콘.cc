#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 1001
using namespace std;

int s;
int visited[MAXN][MAXN];

struct p {
    int x, time, copiednum;
};

bool isRange(int x) {
    return 0 <= x && x <= 1000;
}

int bfs() {
    queue<p> q;
    q.push({1, 0, 0});
    visited[1][0] = 1; 

    while (!q.empty()) {
        p t = q.front();
        q.pop();

        if (t.x == s) {
            return t.time;
        }

        if (visited[t.x][t.x] == 0) {
            visited[t.x][t.x] = 1;
            q.push({t.x, t.time + 1, t.x});
        }
        
        if (t.copiednum > 0 && isRange(t.x + t.copiednum)) { 
            if (visited[t.x + t.copiednum][t.copiednum] == 0) {
                visited[t.x + t.copiednum][t.copiednum] = 1;
                q.push({t.x + t.copiednum, t.time + 1, t.copiednum});
            }
        }

        if (t.x > 0 && visited[t.x - 1][t.copiednum] == 0) { 
            visited[t.x - 1][t.copiednum] = 1;
            q.push({t.x - 1, t.time + 1, t.copiednum}); 
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cout << bfs() << endl;
}
