#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, cnt = 0;
    cin >> num;
    while (num >= 0) {
        if (num % 5 == 0) {
            cnt += (num / 5);
            cout << cnt << endl;
            exit(0);
        } else {
            cnt++;
            num -= 3;
        }
    }
    cout << -1 << endl;
}