#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 9

int n, m;

using namespace std;

int res[MAXN];
map<int, int> m1;

void dfs(int st, int depth){
    if(depth == m){
        loop(i, 0, depth - 1){
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }
    for(auto it = m1.begin(); it != m1.end(); ++it){
        if(st <= it->first){
            res[depth] = it->first;
            dfs(it->first, depth + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int t1;
    loop(i, 0, n - 1){
        cin >> t1;
        m1[t1]++;
    }
    
    dfs(0, 0);
}

