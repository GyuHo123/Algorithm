#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100001

using namespace std;

struct p{
    int x, depth;
};

int n, k, visited[MAXN];

int isRange(int x){
    return 0 <= x && x <= 100000;
}

int bfs() {
    int next;
    queue<p> q;
    q.push({n, 0}); visited[n] = 1;

    while (!q.empty()) {
        p t = q.front(); q.pop();
        if(t.x == k) return t.depth;
        int nx[3] = {t.x + 1, t.x - 1, t.x * 2};
        for (int i = 0; i < 3; i++) {
            next = nx[i];
            if(isRange(next) && !visited[next]){
                q.push({next, t.depth + 1}); visited[next] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        exit(0);
    }
    cout << bfs() << endl;
}