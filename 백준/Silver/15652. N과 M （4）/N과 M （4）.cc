#include<bits/stdc++.h>
using namespace std;

#define MAXN 9

int res[MAXN];
int m, n;

void dfs(int start, int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) cout << res[i] << " ";
        cout << endl;
        return;
    }
    for (int i = start; i <= m; i++) {
        res[depth] = i;
        dfs(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;

    dfs(1, 0);
}
