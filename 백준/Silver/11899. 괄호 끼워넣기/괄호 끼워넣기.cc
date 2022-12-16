#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0, cnt1 = 0;
    string s;

    cin >> s;
    for (char c: s) {
        if (c == ')' && cnt == 0) {
            cnt1++;
        }
        else if (c == '(') {
            cnt++;
        } else if (c == ')') {
            cnt--;
        }
    }
    cout << cnt+cnt1;
}
