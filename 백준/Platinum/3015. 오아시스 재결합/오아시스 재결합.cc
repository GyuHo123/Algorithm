#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height;
    long long cnt = 0;

    pair<int, int> p;

    stack<pair<int, int>> stk;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> height;
        p.first = height, p.second = 1;
        while(!stk.empty() && stk.top().first < p.first){
            cnt += stk.top().second;
            stk.pop();
        }
        if (stk.empty()) {
            stk.push(p);
        }
        else if (stk.top().first > p.first) {
            stk.push(p);
            cnt++;
        } else if (stk.top().first == p.first) {
            p.second += stk.top().second;
            cnt += stk.top().second;
            stk.pop();
            if(!stk.empty()) cnt++;
            stk.push(p);
        }
    }
    cout << cnt;
}