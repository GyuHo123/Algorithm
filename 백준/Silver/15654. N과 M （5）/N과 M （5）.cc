#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 9

using namespace std;

int n, m;

int arr[MAXN], visited[MAXN], res[MAXN];

void dfs(int depth){
    if(depth == m){
        loop(i, 0, m - 1){
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }
    loop(i, 1, n){
        if(!visited[i]){
            visited[i] = 1;
            res[depth] = arr[i];
            dfs(depth + 1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;

    loop(i, 1, n){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1, less<int>());
    dfs(0);
}