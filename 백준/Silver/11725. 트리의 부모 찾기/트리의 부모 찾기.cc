#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;
vector<int> arr[100001];
int p[100001];


void dfs(int cur){
    for(int nx : arr[cur]){
        if(p[cur] == nx) continue;
        p[nx] = cur;
        dfs(nx);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    dfs(1);
    for(int i = 2; i <= n; i++) cout << p[i] << endl;
}
