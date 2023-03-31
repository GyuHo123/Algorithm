#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long

using namespace std;

int n, temp1, temp2, ans = 1;
vector<pair<int, int>> room;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    loop(i, 0, n - 1){
        cin >> temp1 >> temp2;
        room.push_back({temp1, temp2});
    }
    sort(room.begin(), room.end());
    pq.push(room[0].second);
    loop(i, 1, n - 1){
        while(!pq.empty() && pq.top() <= room[i].first){
            pq.pop();
        }
        pq.push(room[i].second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
}