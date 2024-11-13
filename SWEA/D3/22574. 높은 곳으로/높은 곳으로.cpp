#include <iostream>
#define loop(i, s, n) for (int i = s; i <= n; i++)
#define endl '\n'

using namespace std;

int t, n, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        int now = 0;
        cin >> n >> p;

        loop(i, 1, n) {
            if(i + now == p) {
                now = i + now - 1;
                continue;
            }
            now = now + i;
        }
        cout << now << endl;
    }
}