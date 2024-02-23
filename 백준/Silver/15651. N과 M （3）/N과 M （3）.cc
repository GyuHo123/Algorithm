#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 8

using namespace std;

int arr[MAXN];
int visited[MAXN];
int m, n;

void dfs(int num, int k){
    if(k == n){
        loop(i, 0, n - 1){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        loop(i, 1, m){
            arr[k] = i;
            dfs(arr[k], k + 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;

    dfs(1, 0);
}