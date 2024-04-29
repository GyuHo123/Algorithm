#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 21

using namespace std;

int arr[MAXN], n, s;
int cnt;

void sum(int cur, int total){
    if(cur == n + 1){
        if(total == s) cnt++;
        return;
    }
    sum(cur + 1, total);
    sum(cur + 1, total + arr[cur]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    loop(i, 1, n){
        cin >> arr[i];
    }
    sum(1, 0);
    if(!s) cnt -= 1;
    cout << cnt << endl;
}