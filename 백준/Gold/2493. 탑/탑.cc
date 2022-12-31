#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height;

    pair<int, int> p;

    stack<pair<int, int>> stk;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> height;
        p.first = height, p.second = i;
        if (stk.empty()) {
            stk.push(p);
            cout << 0 << " ";
            continue;
        }
        else if(stk.top().first <= p.first) {
            while (true) {
                if (stk.empty()) {
                    cout << 0 << " ";
                    stk.push(p);
                    break;
                }
                int temp = stk.top().first;
                if (temp > p.first) {
                    cout << stk.top().second << " ";
                    stk.push(p);
                    break;
                }
                stk.pop();
            }
        }
        else {
            cout << stk.top().second << " ";
            stk.push(p);
            continue;
        }
    }
}