#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)

using namespace std;

map<int, int> m1;
int temp, n, m, cnt = 0;
queue<int> q1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    loop(i, 1, n){
        cin >> temp;
        m1[temp]++;
    }
    loop(i, 1, m){
        cin >> temp;
        if(m1[temp]){
            m1[temp]--;
        }
    }
    for(auto t : m1){
        if(t.second == 1){
            cnt++;
            q1.push(t.first);
        }
    }
    cout << cnt << endl;
    if(cnt == 0) exit(0);
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
}