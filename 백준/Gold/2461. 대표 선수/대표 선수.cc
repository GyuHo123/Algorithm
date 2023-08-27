#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

int n, m, ans = INT_MAX, arr[MAXN][MAXN];
vector<int> v1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    LOOP(i, 0, n)
        LOOP(j, 0, m){
            cin >> arr[i][j];
            v1.push_back(0);
        }
    loop(i, 0, n - 1) sort(arr[i], arr[i] + m);
    while(1){
        int st = 0, en = INT_MAX, idx;
        loop(i, 0, n - 1){
            if(en > arr[i][v1[i]]){
                en = arr[i][v1[i]];
                idx = i;
            }
            if(st < arr[i][v1[i]]) st = arr[i][v1[i]];
        }
        ans = min(ans, st - en);
        v1[idx]++;
        if(v1[idx] == m) break;
    }
    cout << ans;
}