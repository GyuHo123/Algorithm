#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 200001

using namespace std;

int n;
pair<int, int> room[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    loop(i, 0, n - 1){
        cin >> room[i].first >> room[i].second;
    }
    sort(room, room + n);
    pq.push(room[0].second);
    loop(i, 1, n - 1){
        pq.push(room[i].second);
        if(pq.top() <= room[i].first) pq.pop();
    }
    cout << pq.size();
}