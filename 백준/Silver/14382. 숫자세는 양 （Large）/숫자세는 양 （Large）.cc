#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define MAXN 10

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, inputn;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int visited[MAXN] = {0};
        cin >> inputn;
        if (!inputn) {
            cout << "Case #" << i << ": INSOMNIA" << endl;
            continue;
        }
        int cnt = 1, allvisit = 0, n;
        while (!allvisit) {
            allvisit = 1;
            n = inputn * cnt;
            string s = to_string(n);
            for (char digit : s) {
                visited[digit - '0'] = 1;
            }
            for (int j = 0; j < 10; j++) {
                if (!visited[j]) allvisit = 0;
            }
            if (allvisit) {
                cout << "Case #" << i << ": " << n << endl;
                break;
            }
            cnt++;
        }
    }
}
