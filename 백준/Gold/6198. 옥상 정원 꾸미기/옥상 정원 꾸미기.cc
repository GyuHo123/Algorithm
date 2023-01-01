#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height; long long cnt = 0;

    stack<pair<int, int>> stk;

    pair<int, int> p;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> height;
        p.first = height; p.second = i;
        while(!stk.empty() && p.first >= stk.top().first) {
            cnt += i - stk.top().second - 1;
            stk.pop();
        }
        stk.push(p);
    }
    while(!stk.empty()) {
        cnt += n + 1 - stk.top().second - 1;
        stk.pop();
    }
    cout << cnt;
}