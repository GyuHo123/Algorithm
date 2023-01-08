#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<char> dq;

    int t, n;
    char ch;

    cin >> t;
    for (int i = 0; i < t; i++) {
        dq.clear();
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (dq.empty()) dq.push_back(ch);
            else if (dq.front() < ch) dq.push_back(ch);
            else dq.push_front(ch);
        }
        for (int k = 0; k < dq.size(); k++) {
            cout << dq[k];
        }
        cout << endl;
    }
}