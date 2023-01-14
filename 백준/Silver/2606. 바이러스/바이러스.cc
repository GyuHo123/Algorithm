#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 101

using namespace std;

int cnt, n;

map<int, vector<int>> m;
stack<int> stk;

int arr[MAXN];

int dfs(){
    while(!stk.empty()){
        int t1 = stk.top(); stk.pop();
        for(int i = 0; i < m[t1].size(); i++){
            int nx = m[t1][i];
            if(!arr[nx]){
                stk.push(nx); cnt++; arr[nx] = 1;
            }
        }
    }
    return cnt;
}

int main(){
    int tx, ty, t;
    cin >> t;
    cin >> n;
    arr[1] = 1;
    for(int i = 0; i < n; i++){
        cin >> tx >> ty;
        m[tx].push_back(ty);
        m[ty].push_back(tx);
    }
    for(int i = 0; i < m[1].size(); i++){
        stk.push(m[1][i]);
        arr[m[1][i]] = 1;
        cnt++;
    }
    cout << dfs();
}